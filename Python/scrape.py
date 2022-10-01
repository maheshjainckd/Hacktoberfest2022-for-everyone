#!/usr/bin/env python3
import sys
try:
    import requests
    from requests_html import HTML
    import pandas as pd
except ImportError:
    sys.exit(
        "[!] Please make sure you have installed requests, requests_html and pandas module.")


def url_to_scrap(url, filename="scrapped_data.html"):
    try:
        r = requests.get(url)
        if r.status_code == 200:
            html_text = r.text
            with open(filename, "w") as f:
                f.write(html_text)
            return html_text
        else:
            return None
    except requests.exceptions.ConnectionError:
        return None


def parse_html(html_text):

    # find table with class imdb-scroll-table-inner in html
    table = html_text.find(".imdb-scroll-table-inner")

    table_data = []
    # find all rows in table
    if len(table) == 1:
        parsed_table = table[0]
        rows = parsed_table.find("tr")

        # 1st row is header
        header = rows[0]
        header_cells = header.find("th")
        header_cells_text = [cell.text for cell in header_cells]

        # 2nd row onwards are data rows
        for row in rows[1:]:
            cols = row.find("td")
            row_data = []
            # making list of lists for data so that any data can be easily converted to dataframe
            # if data is having any ',' in it, it will now be considered as a list otherwise it will be a string
            # and csv will read it as a delimiter
            for i, col in enumerate(cols):
                row_data.append(col.text)
            table_data.append(row_data)

        df = pd.DataFrame(table_data, columns=header_cells_text)
        df.to_csv("scrapped_table.csv", index=False)


if __name__ == "__main__":
    URL = "https://www.boxofficemojo.com/year/world/"
    html_text = url_to_scrap(URL)
    if html_text:
        print("[+] Scrapped data saved in scrapped_data.html")
    else:
        print("[!] Unable to scrap data")
        sys.exit(1)

    if parse_html(HTML(html=html_text)) is None:
        print("[+] Scrapped data saved in scrapped_table.csv")
    else:
        print("[!] Unable to parse data")

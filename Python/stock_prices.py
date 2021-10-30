import requests
from bs4 import BeautifulSoup


def stock_price(coin: str = "GOOG") -> str:
    url = f"https://in.finance.yahoo.com/quote/{coin}?s={coin}"
    soup = BeautifulSoup(requests.get(url).text, "html.parser")
    classToCrawl = "My(6px) Pos(r) smartphone_Mt(6px)"
    return soup.find("div", class_=classToCrawl).find("span").text

if __name__ == "__main__":
    coin_input = input('Tell me a coin')
    print(f"{coin_input} stock price is {stock_price(coin_input)}")
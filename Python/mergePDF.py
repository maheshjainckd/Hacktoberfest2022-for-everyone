from PyPDF2 import PdfFileMerger
import os

merger = PdfFileMerger()

path_to_files = r'pdf_files/'

outName = str(input("Final PDF name : "))

if(outName == ""):outName="MergedPDF"

for root, dirs, file_names in os.walk(path_to_files):
    for file_name in file_names:
        merger.append(path_to_files + file_name)

merger.write(f"{outName}.pdf")
merger.close()

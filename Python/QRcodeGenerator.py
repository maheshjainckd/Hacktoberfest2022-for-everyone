import pyqrcode 
from pyqrcode import QRCode 
  
# String which represent the QR code 

s = str(input("Enter Link to generate QR Code"))
  
# Generate QR code 
url = pyqrcode.create(s) 
  
# Create and save the png file naming "
url.svg("MyQRcode.svg", scale = 8)
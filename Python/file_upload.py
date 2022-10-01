#!/usr/bin/env python3

import sys

try:
    import requests
except ImportError:
    print("Please install requests module")
    sys.exit(1)

try:
    UPLOAD_FILE = sys.argv[1]
except IndexError:
    sys.exit('Usage: python3 <path_to_file>')

base_api_url = 'https://api.anonfiles.com'
upload_endpoint = '/upload'

files = {
    'file': (f'{UPLOAD_FILE}', open(f'{UPLOAD_FILE}', 'rb')),
}

r = requests.post(f"{base_api_url}{upload_endpoint}", files=files)
data = r.json()


metadata = data['data']['file']['metadata']
url = data['data']['file']['url']
size = metadata['size']

if not data.get('status'):
    sys.exit(f"[!] {data['error']['message']}")
else:
    print(f"[+] File URL: {url.get('full')}")
    print(f"[+] Short Size: {url.get('short')}")
    print(f"[+] File ID: {metadata.get('id')}")
    print(f"[+] File Name: {metadata.get('name')}")
    print(f"[+] File Size: {size.get('readable')}")

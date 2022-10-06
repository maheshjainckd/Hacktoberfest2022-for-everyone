import requests

ip = requests.get('https://ipinfo.io/json').json()['ip']

print('Your IP is {}'.format(ip))
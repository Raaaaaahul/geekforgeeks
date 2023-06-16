import requests
from bs4 import BeautifulSoup

def itemFetch():
    url = "https://quest.squadcast.tech/public/dom.html"
    response = requests.get(url)
    html_content = response.content
    soup = BeautifulSoup(html_content, "html.parser")
    items = soup.find_all("div")
    if len(items) >= 2655:
        desired_item = items[2655].text.strip()
        print(desired_item)

itemFetch()
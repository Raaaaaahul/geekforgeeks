#"v=spf1 ip4:40.113.200.201 ip6:2001:db8:85a3:8d3:1319:8a2e:370:7348 include:thirdpartydomain.com ~all"

import re

def ipFetch(txt_record):
    ipv4_pattern = r"\b(?:[0-9]{1,3}\.){3}[0-9]{1,3}\b"
    ipv4_addresses = re.findall(ipv4_pattern, txt_record)

    for address in ipv4_addresses:
        print(address)

txt_record = "v=spf1 ip4:40.113.200.201 ip6:2001:db8:85a3:8d3:1319:8a2e:370:7348 include:thirdpartydomain.com ~all"
ipFetch(txt_record)
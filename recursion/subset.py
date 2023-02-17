def findall(s, i, cur, res):
  res.append(cur)
  for idx in range(i, len(s)):
    findall(s, idx + 1, cur + s[idx], res)
        
s = 'abc'
res = [] 
findall(s, 0, "", res)
for i in res:
  print(i)
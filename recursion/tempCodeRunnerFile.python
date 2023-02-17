def solve(n,a,b,c):
    if(n==0):
        return 0
    if(n<0):
        return -1
    res = max(solve(n-a,a,b,c),solve(n-b,a,b,c),solve(n-c,a,b,c))
    if res==-1:
        return -1
    return res + 1

ans = solve(9,2,2,2)
print(ans)
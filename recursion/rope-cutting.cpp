#include<bits/stdc++.h>
using namespace std;
int solve(int n,int a,int b,int c)
{
    if(n==0)
        return 0;
    if(n<0)
        return -1;
    int res = max(solve(n-a,a,b,c),max(solve(n-b,a,b,c),solve(n-c,a,b,c)));
    if(res==-1)
        return -1;
    return ++res;
}
int main()
{
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    int ans = solve(n,a,b,c);
    cout<<ans;
    return 0;
}
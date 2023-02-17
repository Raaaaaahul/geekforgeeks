#include<bits/stdc++.h>
using namespace std;
int counTrailing(int n)
{
    int res = 0;
    for(int i=5;i<=n;i*=5)
    {
        res = res + n/i;
    }
    return res;
}
int main()
{
    int num = 100;
    int ans = counTrailing(num);
    cout<<ans;
    return 0;
}
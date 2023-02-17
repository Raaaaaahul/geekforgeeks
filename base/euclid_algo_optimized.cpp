#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
    int a=15,b=20;
    int ans = gcd(a,b);
    cout<<ans;
    return 0;
}
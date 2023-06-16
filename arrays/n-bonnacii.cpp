#include<bits/stdc++.h>
using namespace std;
void solve(int n,int m)
{
    int a[m] = {0};
    a[n-1] = 1;
    a[n] = 1;

    //sliding window
    for(int i=n+1;i<m;i++)
    {
        a[i] = 2*a[i-1] - a[i-n-1];
    }
    cout<<endl<<a[m-1]<<endl;
}
int main()
{
    int n,m;
    cin>>n>>m;
    solve(n,m);
    return 0;
}
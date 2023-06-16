#include<bits/stdc++.h>
using namespace std;
void solve(int x,int y,int n,int r)
{
    if(x*n>r)
    {
        cout<<-1;return;
    }
    int count = 0;
    while(count<=n)
    {
        int premBurgers = r/y;
        int leftMoney = r%y;
        if(premBurgers==n)
        {
            cout<<"0"<<" "<<n;return;
        }
        else
        {
                                   
        }
    }
}
int main()
{
    int x,y,n,r;
    cin>>x>>y>>n>>r;
    solve(x,y,n,r);
    return 0;
}
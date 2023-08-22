#include<bits/stdc++.h>
using namespace std;
void solve(int n)
{
    if(n<=0)
        return;
    
    cout<<"goku"<<endl;
    n  = n-1;
    solve(n);
}
int main()
{
    int n;
    cin>>n;
    solve(n);
    return 0;
}
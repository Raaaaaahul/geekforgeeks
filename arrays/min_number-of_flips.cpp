#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>& v,int n)
{
    for(int i=1;i<n;i++)
    {
        if(v[i]!=v[i-1])
        {
            if(v[i]!=v[0])
            {
                cout<<"from "<<i<<" to ";
            }
            else
            {
                cout<<i-1<<endl;
            }
        }
    }
    if(v[n-1]!=v[0])
    {
        // cout<<"elements are same";
        cout<<n-1<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    solve(v,n);
    return 0;
}
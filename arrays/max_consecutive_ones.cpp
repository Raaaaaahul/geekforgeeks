#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& v,int n)
{
    int res = 0;
    int curr = 0;
    for(int i=0;i<n;i++)
    {
        if(v[i]==0)
        {
            curr = 0;
        }
        else
        {
            curr++;
            res = max(curr,res);
        }
    }
    return res;
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
    cout<<solve(v,n);
    return 0;
}
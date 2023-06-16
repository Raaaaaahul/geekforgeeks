#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& v,int n)
{
    int lmax[n],rmax[n];
    int res = 0;
    //calculating lmax array
    lmax[0] = v[0];
    for(int i=1;i<n;i++)
    {
        lmax[i] = max(v[i],lmax[i-1]);
    }

    // calculating rmax array
    rmax[n-1] = v[n-1];
    for(int i=n-2;i>=0;i--)
    {
        rmax[i] = max(v[i],rmax[i+1]);
    }
    for(int i=1;i<n-1;i++)
    {
        res = res+(min(lmax[i],rmax[i])-v[i]); 
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
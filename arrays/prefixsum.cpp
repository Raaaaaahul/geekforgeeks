#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& prefix,int l,int r)
{
    if(l!=0)
    {
        return prefix[r] - prefix[l-1];
    }
    else
    {
        return prefix[r];
    }
}
bool equilibriumPoint(vector<int>& v,int n)
{
    int sum = accumulate(v.begin(),v.end(),0);
    int l_sum = 0;
    for(int i=0;i<n;i++)
    {
        if(l_sum == sum - v[i])
        {
            return true;
        }
        l_sum+=v[i];
        sum-=v[i];
    }
    return false;
}
int main()
{
    int size;
    cin>>size;
    vector<int> v(size);
    for(int i=0;i<size;i++)
    {
        cin>>v[i];
    }
    vector<int> prefix(size);
    prefix[0]=v[0];
    for(int i=1;i<size;i++)
    {
        prefix[i] = prefix[i-1] + v[i];
    }
    // int l,r;
    // cin>>l>>r;
    // int ans = solve(prefix,l,r);
    // cout<<ans;
    if(equilibriumPoint(v,size))
    {
        cout<<"there is equilibrium point"<<endl;
    }
    else
    {
        cout<<"No equilibrium point"<<endl;
    }
    return 0;
}
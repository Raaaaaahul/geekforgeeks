#include<bits/stdc++.h>
using namespace std;
int helper(vector<int>& v,int n,int k)
{
    unordered_map<int,int> mp;
    int sum = 0,maxLen = 0;
    for(int i=0;i<n;i++)
    {
        sum+=v[i];
        if(sum==k)
        {
            maxLen = i+1;
        }
        if(mp.find(sum)==mp.end())
        {
            mp[sum]=i;
        }

        if(mp.find(sum - k)!=mp.end())
        {
            maxLen = max(maxLen,i - mp[sum-k]);
        }
    }
    return maxLen;
}
int solve(vector<int>& v,int n)
{
    for(int i=0;i<n;i++)
    {
        if(v[i]==0)
        {
            v[i] = -1;
        }
    }
    int ans = helper(v,n,0);
    return ans;
}
int main()
{
    int n;
    cout<<"enter size"<<endl;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<solve(v,n);
}
#include<bits/stdc++.h>
using namespace std;
int helper(vector<int>& v,int n,int k=0)
{
    unordered_map<int,int> mp;
    int sum = 0,maxLen=0;
    for(int i=0;i<n;i++)
    {
        sum+=v[i];
        if(sum==k)
        {
            maxLen = i+1;
        }
        if(mp.find(sum)==mp.end())
        {
            mp[sum] = i;
        }
        if(mp.find(sum-k)!=mp.end())
        {
            maxLen = max(maxLen,i - mp[sum - k]);
        }
    }
    return maxLen;
}
int solve(vector<int>& arr1,vector<int>& arr2,int n)
{
    vector<int> temp(n);
    for(int i=0;i<n;i++)
    {
        temp.push_back(arr1[i] - arr2[i]);
    }
    int ans = helper(temp,n);
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr1(n);
    vector<int> arr2(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>arr2[i];
    }
    int ans = solve(arr1,arr2,n);
    cout<<ans;
    return 0;
}
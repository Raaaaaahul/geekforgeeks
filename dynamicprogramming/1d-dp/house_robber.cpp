#include<bits/stdc++.h>
using namespace std;

int solve(int idx,vector<int>& v,vector<int>& dp)
{
    if(idx==0)
    {
        return v[idx];
    }
    if(idx<0)
    {
        return 0;
    }
    if(dp[idx]!=-1)
    {
        return dp[idx];
    }
    int pick = v[idx] + solve(idx-2,v,dp);
    int notpick = 0+solve(idx-1,v,dp);
    return dp[idx] = max(pick,notpick);
}

int maxAdj(vector<int>& v)
{
    int n = v.size();
    vector<int> dp(n,-1);
    return solve(n-1,v,dp);
}

int main()
{
    vector<int> arr{1,5,1,2,6};
    int n=arr.size();
    vector<int> v1{arr.begin(),arr.end()-1};
    vector<int> v2{arr.begin()+1,arr.end()};
    int ans1 = maxAdj(v1);
    int ans2 = maxAdj(v2);
    if(ans1>ans2)
    {
        cout<<ans1;
    }
    else
    {
        cout<<ans2;
    }
    return 0;
}
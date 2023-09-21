#include<bits/stdc++.h>
using namespace std;
int helper(int idx,int k,vector<int>& v,vector<vector<int>>& dp)
{
    if(k==0)
    {
        return 1;
    }
    if(idx==0)
    {
        if(v[idx]==k)   return 1;
        return 0;
    }
    if(dp[idx][k]!=-1)
    {
        return dp[idx][k];
    }
    int notTake = helper(idx-1,k,v,dp);
    int take = 0;
    if(v[idx]<=k)
    {
        take = helper(idx-1,k - v[idx],v,dp);
    }
    return dp[idx][k] = take+notTake;
}
int solve(vector<int>& v,int n,int k)
{
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return helper(n-1,k,v,dp);
}
int main()
{
    vector<int> v{1,3,2};
    int k = 6;
    int n = v.size();
    cout<<solve(v,k,n);
    return 0;
}
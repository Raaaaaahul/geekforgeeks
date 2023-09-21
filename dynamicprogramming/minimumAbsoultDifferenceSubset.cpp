#include<bits/stdc++.h>
using namespace std;

bool Fill(int idx,int k,vector<int>& v,vector<vector<int>>& dp)
{
    if(k==0)
    {
        return true;
    }
    if(idx==0)
    {
        return (v[0]==k);
    }
    if(dp[idx][k]!=-1)
    {
        return dp[idx][k];
    }
    bool notTake = Fill(idx-1,k,v,dp);
    bool take = false;
    if(v[idx]<=k)
    {
        take = Fill(idx-1,k - v[idx],v,dp);
    }
    return dp[idx][k] = take or notTake;
}

int minDiff(vector<int>& v,int n)
{
    int sum = 0;
    for(auto it:v)
    {
        sum+=it;
    }
    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    for(int i=0;i<=sum;i++)
    {
        bool dummy = Fill(n-1,i,v,dp);
    }
    int mini = INT_MAX;
    for(int i=0;i<=sum;i++)
    {
        if(dp[n-1][i])
        {
            int diff = abs(i-(sum - i));
            mini = min(mini,diff);
        }
    }
    return mini;
}
int main()
{
    vector<int> v{4,11,8,8,1,9,2};
    int n = v.size();
    cout<<minDiff(v,n);
    return 0;
}
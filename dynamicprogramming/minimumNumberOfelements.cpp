#include<bits/stdc++.h>
using namespace std;

int solve(int idx,int x,vector<int>& v,vector<vector<int>>& dp)
{
    if(idx==0)
    {
        if(x%v[0]==0)
        {
            return x/v[0];
        }
        else
            return 1e9;
    }

    if(dp[idx][x]!=-1)
    {
        return dp[idx][x];
    }

    int notTake = solve(idx-1,x,v,dp)+0;
    int take = 1e9;
    if(v[idx]<=x)
    {
        take = 1+solve(idx,x-v[idx],v,dp);
    }
    return dp[idx][x] = min(take,notTake);
}

int main()
{
    vector<int> v{1,2,3};
    int x = 15;
    int n = v.size();
    vector<vector<int>> dp(n,vector<int>(x+1,-1));
    int ans = solve(n-1,x,v,dp);   
    if(ans>=1e9)
    {
        cout<<-1;
        exit(0);
    }
    else
    {
        cout<<ans;
    }
    return 0;
}
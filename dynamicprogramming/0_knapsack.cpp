#include<bits/stdc++.h>
using namespace std;

int mem(int idx,int w,vector<int>& val,vector<int>& wt,vector<vector<int>>& dp)
{
    if(idx==0)
    {
        if(wt[idx]<=w)
        {
            return val[idx];
        }
        return 0;
    }
    if(dp[idx][w]!=-1)
    {
        return dp[idx][w];
    }
    int take = INT_MIN;
    int notTake  = 0+mem(idx-1,w,val,wt,dp);
    if(wt[idx]<w)
    {
        take = val[idx] + mem(idx-1,w-wt[idx],val,wt,dp);
    }
    return dp[idx][wt] = max(take,notTake);
}

int solve(int n,int w,vector<int>& val,vector<int>& wt)
{
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    return mem(n-1,w,val,wt,dp);
}
int main()
{
    vector<int> val{30,20,40};
    vector<int> wt{2,4,1};
    int w = 4;
    int n = val.size();
    cout<<solve(n,w,val,wt);
    return 0;
}
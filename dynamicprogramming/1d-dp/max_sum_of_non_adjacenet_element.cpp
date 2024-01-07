#include<bits/stdc++.h>
using namespace std;

int max_non_adjacent_sum(int idx,vector<int>& v,vector<int>& dp)
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
    int pick = v[idx]+max_non_adjacent_sum(idx-2,v,dp);
    int nonpick = 0+max_non_adjacent_sum(idx-1,v,dp);
    return dp[idx] = max(pick,nonpick);
}

int main()
{

    vector<int> v{2,1,4,9};
    int n = 4;
    vector<int> dp(n,-1);
    cout<<max_non_adjacent_sum(n-1,v,dp);
    return 0;
}
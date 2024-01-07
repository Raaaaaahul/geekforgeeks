#include<bits/stdc++.h>
using namespace std;

int climb_ways(int n)
{
    if(n==1 or n==0)
    {
        return 1;
    }
    return climb_ways(n-1) + climb_ways(n-2);
}

int climb_ways_mem(int n,vector<int>& dp)
{
    if(n==1 or n==0)
    {
        return 1;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    return dp[n] = climb_ways_mem(n-1,dp)+climb_ways_mem(n-2,dp);
}

int main()
{
    int number_of_stairs = 17;
    int ans = climb_ways(number_of_stairs);
    vector<int> dp(number_of_stairs+1,-1);
    ans = climb_ways_mem(number_of_stairs,dp);
    cout<<ans;
    return 0;
}
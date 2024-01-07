#include<bits/stdc++.h>
using namespace std;

int min_energy(int idx,vector<int>& ht,vector<int>& dp,int k)
{
    if(idx==0)
    {
        return 0;
    }
    if(dp[idx]!=-1)
    {
        return dp[idx];
    }
    int energy = INT_MAX;
    for(int i=1;i<=k;i++)
    {
        if(idx-i>=0)
        {
            int jump = min_energy(idx-i,ht,dp,k) + abs(ht[idx] - ht[idx-i]);
            energy = min(jump,energy);
        }
    }
    return dp[idx] = energy;
}

int main()
{
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    int k = 4;
    vector<int> dp(n,-1);
    int ans = min_energy(n-1,height,dp,k);
    cout<<ans;
    return 0;
}
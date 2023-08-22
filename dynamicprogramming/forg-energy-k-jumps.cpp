#include<bits/stdc++.h>
using namespace std;

int mem(int idx,int k,vector<int>& nums,vector<int>& dp)
{
    if(idx==0)
        return 0;
    
    if(dp[idx]!=-1)
        return dp[idx];
    
    int min_energy = INT_MAX;
    for(int j=1;j<=k;j++)
    {
        if(idx-j>=0)
        {
            int jump = mem(idx-j,k,nums,dp) + abs(nums[idx] - nums[idx-j]);
            min_energy =min(min_energy,jump);
        }
    }
    return dp[idx] = min_energy;
}
int solve(int n,int k,vector<int>& nums)
{
    vector<int> dp(n,-1);
    return mem(n-1,k,nums,dp);
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<solve(n,k,nums);
    return 0;
}
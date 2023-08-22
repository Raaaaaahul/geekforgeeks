#include<bits/stdc++.h>
using namespace std;
int mem(int idx,vector<int>& nums,vector<int>& dp)
{
    if(idx==0)
        return 0;
    
    if(dp[idx]!=-1)
        return dp[idx];
    
    int left=INT_MAX,right=INT_MAX;
    left = mem(idx-1,nums,dp) + abs(nums[idx] - nums[idx-1]);
    if(idx>1)
    {
        right = mem(idx-2,nums,dp) + abs(nums[idx] - nums[idx-2]);
    }
    return dp[idx] = min(left,right);
}
int solve(int n,vector<int>& nums)
{
    vector<int> dp(n+1,-1);
    return mem(n-1,nums,dp);
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<"minimum energy required is : "<<solve(n,nums);
    return 0;
}
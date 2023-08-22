#include<bits/stdc++.h>
using namespace std;
int mem(int n,vector<int>& dp,vector<int>& nums)
{
    if(n==0)
        return nums[0];
    
    if(n<0)
        return 0;
    
    if(dp[n]!=-1)
        return dp[n];
    
    //include
    int include = nums[n] + mem(n-2,dp,nums);
    int exclude = mem(n-1,dp,nums);
    return dp[n] = max(include,exclude);
}
int solve(int n,vector<int>& nums)
{
    vector<int> dp(n+1,-1);
    return mem(n,dp,nums);
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
    cout<<solve(n,nums);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
    int solve(int idx,int target,vector<int>& arr,vector<vector<int>>& dp)
{
    if(idx==0)
    {
        if(target==0 and arr[0]==0)
        {
            return 2;
        }
        if(target==0 or target==arr[0])
        {
            return 1;
        }
        return 0;
    }
    
    if(dp[idx][target]!=-1)
    {
        return dp[idx][target];
    }

    int notTake = solve(idx-1,target,arr,dp);
    int take = 0;
    if(arr[idx]<=target)
    {
        take = solve(idx-1,target-arr[idx],arr,dp);
    }
    return dp[idx][target] = (take+notTake);
}
int targetSum(int n, int target, vector<int> &arr) {
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    if(sum-target<0)
    {
        return 0;
    }
    if((sum-target)%2==1)
    {
        return 0;
    }       
    int s2 = (sum-target)/2;
    vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    return solve(n-1,s2,arr,dp);
}
int main()
{
  vector<int> arr = {1,2,3,1};
  int target=3;
                     
  int n = arr.size();            
  cout<<"The number of ways found is " <<targetSum(n,target,arr);
}
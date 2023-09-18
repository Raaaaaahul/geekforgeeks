#include<bits/stdc++.h>
using namespace std;
bool solve_rec(int idx,int k,vector<int>& v)
{
    if(k==0)
    {
        return false;
    }
    if(idx==0)
    {
        return (v[0]==k);
    }
    bool notTake = solve_rec(idx-1,k,v);
    bool take = false;
    if(v[idx]<=k)
    {
        take = solve_rec(idx-1,k-v[idx],v);
    }
    return take or notTake;
}
bool mem(int idx,int k,vector<int>& v,vector<vector<int>>& dp)
{
    //if we target becomes 0 we then we can say there exist a subset
    if(k==0)
    {
        return true;
    }
    //if we reach the end of array we can only return true if the remaining target is equal to the last element of the array
    if(idx==0)
    {
        return (v[0]==k);
    }
    //memoisation
    if(dp[idx][k]!=-1)
    {
        return dp[idx][k];
    }
    //not take the particular idx of the array
    bool notTake = mem(idx-1,k,v,dp);
    //take the current element and check for remaining elements in the array
    bool take = false;
    if(v[idx]<=k)
    {
        take = mem(idx-1,k-v[idx],v,dp);
    }
    return dp[idx][k] = take | notTake;
}
bool solve(vector<int>& v,int target)
{
    int n =v.size();
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    return mem(n-1,target,v,dp);
    // return solve_rec(n-1,target,v);
}
int main()
{
    vector<int> v{2,3,1,1};
    int target = 4;
    cout<<solve(v,target);
    return 0;
}

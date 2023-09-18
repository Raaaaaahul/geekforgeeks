#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9;
int solve(int n,int k,vector<vector<int>>& dp)
{
    if(n==0)
        return 0;
    if(k==0)
        return 0;
    if(dp[n][k]!=-1)   
        return dp[n][k];
    
    return dp[n][k] = ((1+solve(n-1,k,dp) + solve(n,k-1,dp)))%mod;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
    cout<<solve(n,k,dp);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int unique_paths(int i,int j,vector<vector<int>>& dp)
{
    if(i==0 and j==0)
        return 1;
    if(i<0 or j<0)
        return 0;
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int up = unique_paths(i-1,j,dp);
    int left = unique_paths(i,j-1,dp);
    return dp[i][j] = up+left;
}
int main()
{
    int m = 3;
    int n = 2;
    vector<vector<int>> dp(m,vector<int>(n,-1));
    cout<<unique_paths(m-1,n-1,dp);
    return 0;
}
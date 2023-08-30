#include<bits/stdc++.h>
using namespace std;
int solve(int i,int j,vector<vector<int>>& dp)
{
    if(i==0 and j==0)
        return 1;
    
    if(i<0 or j<0)
        return 0;
    
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    int up = solve(i-1,j,dp);
    int left = solve(i,j-1,dp);
    
    return dp[i][j] = up+left;

}
int main()
{
    int m =3,n=2;
    vector<vector<int>> dp(m,vector<int>(n,-1));
    cout<<solve(m-1,n-1,dp);
    return 0;
}
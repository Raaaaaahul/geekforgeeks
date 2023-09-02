#include<bits/stdc++.h>
using namespace std;
int solve(int i,int j,vector<vector<int>>& maze,vector<vector<int>>& dp)
{
    if(i==0 and j==0)
    {
        return maze[0][0];
    }
    if(i<0 or j<0)
    {
        return 1e9; //invalid
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int up = solve(i-1,j,maze,dp) + maze[i][j];
    int left = solve(i,j-1,maze,dp) + maze[i][j];
    return dp[i][j] = min(up,left);
}
int main()
{
    vector<vector<int> > maze{{1,3,1},
                            {1,5,1},
                            {4,2,1}};
    
    int n = maze.size();
    int m = maze[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    cout<<solve(n-1,m-1,maze,dp);
    return 0;
}
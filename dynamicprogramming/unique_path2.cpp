#include<bits/stdc++.h>
using namespace std;

int solve(int i,int j,vector<vector<int>>& maze,vector<vector<int>>& dp)
{
    if(i>=0 and j>=0 and maze[i][j]!=-1)
    {
        return 0;
    }
    if(i==0 and j==0)
    {
        return 1;
    }
    if(i<0 or j<0)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    int up = solve(i-1,j,maze,dp);
    int left = solve(i,j-1,maze,dp);
    return dp[i][j] = up + left;
}

int rec(int n,int m,vector<vector<int>>& maze)
{
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return solve(n-1,m-1,maze,dp);
}

int main()
{

  vector<vector<int> > maze{{0,0,0},
                            {0,-1,0},
                            {0,0,0}};
                            
  int n = maze.size();
  int m = maze[0].size();
  
  cout<<rec(n,m,maze);
}
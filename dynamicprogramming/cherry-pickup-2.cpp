#include<bits/stdc++.h>

using namespace std;

int maxChocoUtil(int i, int j1, int j2, int n, int m, vector < vector < int >> & grid, vector < vector < vector < int >>> & dp) 
{
    //out of bound problem
    if(j1<0 or j2<0 or j1>=m or j2>=m)
    {
        return -1e9;
    }
    //if it reaches the last row
    if(i==n-1)
    {
        if(j1==j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1)
    {
        return dp[i][j1][j2];
    }
    int maxi = -1e9;
    for(int di = -1;di<=1;di++)
    {
        for(int dj=-1;dj<=1;dj++)
        {
            int ans;
            if(j1==j2)
            {
                ans = grid[i][j1] + maxChocoUtil(i+1,j1+di,j2+dj,n,m,grid,dp);
            }
            else
            {
                ans = grid[i][j1] + grid[i][j2] + maxChocoUtil(i+1,j1+di,j2+dj,n,m,grid,dp);
            }
            maxi = max(maxi,ans);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int n, int m, vector < vector < int >> & grid) 
{
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
    return maxChocoUtil(0,0,m-1,n,m,grid,dp);
}

int main() {

   vector<vector<int> > matrix{
      {3,1,1},
      {2,5,1},
      {1,5,5},
      {2,1,1}
  };

  int n = matrix.size();
  int m = matrix[0].size();

  cout << maximumChocolates(n, m, matrix);
}
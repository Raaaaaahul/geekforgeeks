#include<bits/stdc++.h>
using namespace std;
//i = n-1 last row idx
//j changing idx
//m size of each row
//mat = original matrix
//dp 2d array for memoisation
int solve(int i,int j,int m,vector<vector<int>>& mat,vector<vector<int>>& dp)
{
    if(j<0 or j>=m)
    {
        return -1e9;
    }
    if(i==0)
    {
        return mat[i][j];
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    int up = mat[i][j] + solve(i-1,j,m,mat,dp);
    int left_diag = mat[i][j] + solve(i-1,j-1,m,mat,dp);
    int right_diag = mat[i][j] + solve(i-1,j+1,m,mat,dp);
    return dp[i][j] = max(up,max(left_diag,right_diag));
}

int getMaxPathSum(vector<vector<int>>& mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    int maxi = INT_MIN;
    //starting from the last row we try to reach to the first row
    //since we can start from any index of the last row we will be using a for loop
    for(int j=0;j<m;j++)
    {
        int ans = solve(n-1,j,m,mat,dp);
        maxi = max(maxi,ans);
    }
    return maxi;
}

int main() {

  vector<vector<int> > matrix{{1,2,10,4},
                              {100,3,2,1},
                              {1,1,20,2},
                              {1,2,2,1}};
  
  cout<<getMaxPathSum(matrix);
}
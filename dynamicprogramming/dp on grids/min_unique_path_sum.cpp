#include<bits/stdc++.h>
using namespace std;

int helper(int i,int j,vector<vector<int>>& mat,vector<vector<int>>& dp)
{
    if(i==0 and j==0)
    {
        return mat[i][j];
    }
    if(i<0 or j<0)
    {
        return 1e9;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int up = mat[i][j] + helper(i-1,j,mat,dp);
    int left = mat[i][j]+helper(i,j-1,mat,dp);
    return dp[i][j] = min(up,left);
}

int minSumPath(int n,int m,vector<vector<int>>& mat)
{
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return helper(n-1,m-1,mat,dp);
}

int main() 
{
    vector<vector<int>> matrix{
        {5, 9, 6},
        {11, 5, 2}
    };

    int n = matrix.size();
    int m = matrix[0].size();

    cout << "Minimum sum path: " << minSumPath(n, m, matrix) << endl;
    return 0;
}
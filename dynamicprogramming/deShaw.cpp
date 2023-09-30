#include<bits/stdc++.h>
using namespace std;

int solve(string a,string b,int i,int j,int x,int y,vector<vector<int>>& dp)
{
  if(i==0)
  {
    return j*x;
  }
  if(j==0)
  {
    return i*x;
  }

  if(dp[i][j]!=-1)
  {
    return dp[i][j];
  }

  if(a[i-1]==b[j-1])
  {
    dp[i][j] = solve(a,b,i-1,j-1,x,y,dp);
  }
  else
  {
    int op1 = solve(a,b,i-1,j,x,y,dp) + x;
    int op2 = solve(a,b,i,j-1,x,y,dp) + x;
    int op3 = solve(a,b,i-1,j-1,x,y,dp) + y;
    dp[i][j] = min(op1,min(op2,op3));
  }
  

  return dp[i][j];
}

int main()
{
  string a = "chat window";
  string b = "cheat wilow";
  int x = 3;
  int y = 5;

  int m = a.size();
  int n = b.size();

  vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
  int ans = solve(a,b,m,n,x,y,dp);
  cout<<ans;
  return 0;
}

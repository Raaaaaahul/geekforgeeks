#include<bits/stdc++.h>
using namespace std;

int lcs(int n,int m,string s,string t,vector<vector<int>>& dp)
{
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++)
    {
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string s = "leetcode";
    string t = "eat";
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    int len = lcs(n,m,s,t,dp);
    cout<<n+m-2*len;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int solve(int i,int j,string s,string t,vector<vector<int>>& dp)
{
    int n = s.size();
    int m = t.size();

    for(int i=0;i<=n;i++)
    {
        dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++)
    {
        dp[0][i] = 0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
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
    string s = "abac";
    string t = "cab";
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    int len = solve(n-1,m-1,s,t,dp);
    int i = n;
    int j = m;
    string ans;
    while(i>0 and j>0)
    {
        if(s[i-1]==t[j-1])
        {
            ans+=s[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
        {
            ans += s[i-1];
            i--;
        }
        else
        {
            ans += t[j-1];
            j--;
        }
    }
    while(i>0)
    {
        ans += s[i-1];
        i--;
    }
    while(j>0)
    {
        ans += t[j-1];
        j--;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;
}
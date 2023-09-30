#include<bits/stdc++.h>
using namespace std;

int solve(string& s1,string& s2,int n,int m)
{
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++)
        {
            dp[i][0] = 0;
        }
        for(int i=0;i<=m;i++)
        {
            dp[0][i] = 0;
        }
        int ans = 0;
        for(int idx1 = 1;idx1<=n;idx1++)
        {
            for(int idx2 = 1;idx2<=m;idx2++)
            {
                if(s1[idx1-1]==s2[idx2-1])
                {
                    dp[idx1][idx2] = dp[idx1-1][idx2-1]+1;
                    ans = max(ans,dp[idx1][idx2]);
                }
                else
                {
                    dp[idx1][idx2] = 0;
                }
            }
        }
        return ans;
}

int main()
{
    string s1 = "abcde";
    string s2 = "badcbcde";
    int n = s1.size();
    int m = s2.size();
    int ans = solve(s1,s2,n,m);
    cout<<ans;
    return 0;
}
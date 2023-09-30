#include <bits/stdc++.h>

using namespace std;

int lcsUtil(string& s1, string& s2, int ind1, int ind2,  vector<vector<int>>& dp){

    if(ind1<0 || ind2<0)
        return 0;
        
    if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];
    
    if(s1[ind1] == s2[ind2])
        return dp[ind1][ind2] = 1 + lcsUtil(s1,s2,ind1-1,ind2-1,dp);
    
    else 
        return dp[ind1][ind2] = 0 + max(lcsUtil(s1,s2,ind1,ind2-1,dp),lcsUtil (s1,s2,ind1-1,ind2,dp));
   
}


int lcsTab(string s1,string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

    for(int i=0;i<=n;i++)
    {
        dp[i][0] = 0;
    }

    for(int i=0;i<=m;i++)
    {
        dp[0][i] = 0;
    }

    for(int idx1 = 1;idx1<=n;idx1++)
    {
        for(int idx2 = 1;idx2<=m;idx2++)
        {
            if(s1[idx1-1]==s2[idx2-1])
            {
                dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
            }
            else
            {
                dp[idx1][idx2] = 0 + max(dp[idx1-1][idx2],dp[idx1][idx2-1]);
            }
        }
    }
    return dp[n][m];
}


int lcs(string s1, string s2) {
    
    int n=s1.size();
    int m=s2.size();

    vector<vector<int>> dp(n,vector<int>(m,-1));
    return lcsUtil(s1,s2,n-1,m-1,dp);
}

int main() 
    {

  string s1= "acd";
  string s2= "ced";
                                 
  cout<<"The Length of Longest Common Subsequence is "<<lcsTab(s1,s2);
}
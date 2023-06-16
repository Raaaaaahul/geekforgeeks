#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        int dp[m+1][n+1];

        for(int i=0;i<=m;i++)
        {
            dp[i][0] = i;
        }
        for(int j=0;j<=n;j++)
        {
            dp[0][j]=j;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    int ins = dp[i][j-1];
                    int del = dp[i-1][j];
                    int rep = dp[i-1][j-1];
                    dp[i][j] = 1 + min({ins,del,rep});
                }
            }
        }
        return dp[m][n];
    }
};
int main()
{
    Solution obj;
    string s1,s2;
    std::cin>>s1>>s2;
    int ans = obj.minDistance(s1,s2);
    std::cout<<ans;

    return 0;
}

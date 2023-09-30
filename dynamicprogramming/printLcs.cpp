#include <bits/stdc++.h>
using namespace std;
string lcs(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int len = dp[n][m];
    int idx = len - 1;
    string str = "";
    int i = n;
    int j = m;
    for (int k = 1; k <= len; k++)
    {
        str += "$";
    }

    while (i > 0 and j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            str[idx] = s1[i - 1];
            idx--;
            i--;
            j--;
        }
        else if (s1[i - 1] > s2[j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    return str;
}
int main()
{
    string s1 = "abcde";
    string s2 = "bdgek";
    string ans = lcs(s1, s2);
    cout << ans;
    return 0;
}

int longestCommonSubsequence(string text1, string text2, vector<vector<int>> &dp)
{

    int n = text1.size();

    int m = text2.size();

    for (int i = 0; i <= n; i++)
    {

        dp[i][0] = 0;
    }

    for (int i = 0; i <= m; i++)
    {

        dp[0][i] = 0;
    }

    for (int index1 = 1; index1 <= n; index1++)
    {

        for (int index2 = 1; index2 <= m; index2++)
        {

            if (text1[index1 - 1] == text2[index2 - 1])

            {

                dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
            }

            else
                dp[index1][index2] = max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
        }
    }

    return dp[n][m];
}

string findLCS(int n, int m, string &s1, string &s2)
{

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int len = longestCommonSubsequence(s1, s2, dp);

    string ans;

    int i = n;

    int j = m;

    while (i > 0 && j > 0)
    {

        if (s1[i - 1] == s2[j - 1])
        {

            ans.push_back(s1[i - 1]);

            i--;

            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {

            i--;
        }
        else
        {

            j--;
        }
    }

    reverse(ans.begin(), ans.end());

    return ans; // reverse string
}
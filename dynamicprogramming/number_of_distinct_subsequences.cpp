#include<bits/stdc++.h>
using namespace std;

int solve(int i, int j, int n, int m, string& s1, string& s2, vector<vector<int>>& dp) {
    if (j < 0) {
        return 1;
    }
    if (i < 0) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    if (s1[i] == s2[j]) {
        int leaveOne = solve(i - 1, j - 1, n, m, s1, s2, dp);
        int stay = solve(i - 1, j, n, m, s1, s2, dp);
        dp[i][j] = leaveOne + stay;
    }
    else {
        dp[i][j] = solve(i - 1, j, n, m, s1, s2, dp);
    }
    return dp[i][j];
}

int main() {
    string s1 = "babgbag";
    string s2 = "bag";
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = solve(n - 1, m - 1, n, m, s1, s2, dp);
    cout << ans;
    return 0;
}

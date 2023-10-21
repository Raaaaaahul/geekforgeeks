#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main() {
    string A, B;
    cin >> A >> B;
    int n = A.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (A[i - 1] == B[i - 1]) {
            dp[i] = dp[i - 1];
        } else {
            dp[i] = (2 * dp[i - 1]) % mod;
        }
    }
    cout << dp[n] << endl;
    return 0;
}

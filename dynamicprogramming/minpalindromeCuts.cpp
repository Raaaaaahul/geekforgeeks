#include <iostream>
#include <vector>
using namespace std;

int minPalindromeCuts(string s) {
    int n = s.length();
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
    vector<int> minCuts(n);

    for (int i = 0; i < n; i++) {
        minCuts[i] = i; // Initialize minCuts with worst case cuts
        for (int j = 0; j <= i; j++) {
            if (s[i] == s[j] && (i - j <= 1 || isPalindrome[j + 1][i - 1])) {
                isPalindrome[j][i] = true;
                if (j == 0) {
                    minCuts[i] = 0;
                } else {
                    minCuts[i] = min(minCuts[i], minCuts[j - 1] + 1);
                }
            }
        }
    }

    return minCuts[n - 1];
}

int main() {
    cout << minPalindromeCuts("APPLPPA") << endl;   // Output: 0
    cout << minPalindromeCuts("APPLE") << endl;     // Output: 3
    cout << minPalindromeCuts("AMMAMADAM") << endl; // Output: 1

    return 0;
}

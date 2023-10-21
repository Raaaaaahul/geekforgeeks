#include<bits/stdc++.h>
using namespace std;

int largestSquare(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    vector<vector<int>> prefixSum(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            prefixSum[i][j] = matrix[i-1][j-1] + prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];
        }
    }
    int left = 0, right = n, ans = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        bool found = false;
        for(int i=mid; i<=n; i++) {
            for(int j=mid; j<=n; j++) {
                if(prefixSum[i][j] - prefixSum[i-mid][j] - prefixSum[i][j-mid] + prefixSum[i-mid][j-mid] <= k) {
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        if(found) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << largestSquare(matrix, k) << endl;
    return 0;
}

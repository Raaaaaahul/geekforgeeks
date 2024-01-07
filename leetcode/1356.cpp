#include <bits/stdc++.h>
using namespace std;

int helper(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

bool compare(const int& a, const int& b) {
    int a1s = helper(a);
    int b1s = helper(b);
    if (a1s == b1s) {
        // If the number of 1 bits is the same, sort based on the actual values
        return a < b;
    }
    return a1s < b1s;
}

int main() {
    vector<int> arr{1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
    sort(arr.begin(), arr.end(), compare);
    for (auto it : arr) {
        cout << it << " ";
    }
    return 0;
}
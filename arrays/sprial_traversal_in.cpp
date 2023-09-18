#include <bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) {
    int total = r * c;
    vector<int> ans;
    int count = 0;

    int startRow = 0;
    int startCol = 0;
    int endRow = r - 1;
    int endCol = c - 1;

    while (count < total) {
        for (int i = startCol; i <= endCol and count < total; i++) {
            count++;
            ans.push_back(matrix[startRow][i]);
        }
        startRow++;

        for (int i = startRow; i <= endRow and count < total; i++) {
            count++;
            ans.push_back(matrix[i][endCol]);
        }
        endCol--;

        for (int i = endCol; i >= startCol and count < total; i--) {
            ans.push_back(matrix[endRow][i]);
            count++;
        }
        endRow--;

        for (int i = endRow; i >= startRow and count < total; i--) {
            count++;
            ans.push_back(matrix[i][startCol]);
        }
        startCol++;
    }
    return ans;
}

int main() {
    vector<vector<int>> v{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int r = v.size();
    int c = v[0].size();
    vector<int> ans = spirallyTraverse(v, r, c);
    for (auto it : ans) {
        cout << it << " ";
    }
    return 0;
}

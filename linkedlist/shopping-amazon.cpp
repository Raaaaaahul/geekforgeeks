#include <bits/stdc++.h> 
using namespace std;

int solve(int n, vector<vector<int>>& edges) {
    vector<vector<bool>> isEdge(n + 1, vector<bool>(n + 1, false));
    vector<int> degree(n + 1, 0);

    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        isEdge[u][v] = isEdge[v][u] = true;
        degree[u]++;
        degree[v]++;
    }

    int result = INT_MAX;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (isEdge[i][j]) { // i and j are connected
                for (int k = j + 1; k <= n; k++) {
                    if (isEdge[i][k] && isEdge[j][k]) { // i, j, and k form a "trio"
                        int count = degree[i] + degree[j] + degree[k] - 6;
                        result = min(result, count);
                    }
                }
            }
        }
    }

    return (result == INT_MAX) ? -1 : result;
}

int main() {
    int n = 6;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {3, 2}, {4, 1}, {5, 2}, {3, 6}};
    int ans = solve(n, edges);
    cout << ans;
    return 0;
}

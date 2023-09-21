#include<bits/stdc++.h>
using namespace std;

int dfs(int node,vector<vector<int>>& g,vector<int>& vis)
{
    vis[node] = 1;
    //outdegree
    int ans = g[node].size();
    for (auto it :g[node])
    {
        if(vis[it]==0)
        {
            dfs(it,g,vis);
        }
    }
    return ans;
}

int isCircle(vector<string>& a,int n)
{
    //graph creation
    vector<vector<int>> g(26);
    vector<int> indeg(26,0);
    vector<int> outdeg(26,0);

    for(auto it:a)
    {
        int u = it.front() - 'a';
        int v = it.back() - 'a';

        g[u].push_back(v);
        indeg[v]++;
        outdeg[u]++;
    }
    for(int i=0;i<26;i++)
    {
        if(indeg[i]!=outdeg[i])
        {
            return 0;
        }
    }
    vector<int> vis(26,0);
    return n==dfs(a[0][0] - 'a',g,vis);
}
int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        a[i] = temp; // Use assignment to fill the vector correctly.
    }
    cout << isCircle(a, n);
    return 0;
}
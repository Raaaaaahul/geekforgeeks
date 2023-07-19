#include<bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>>& g,vector<int>& indegree)
{
    for(int i=0;i<g.size();i++)
    {
        for(int it : g[i])
        {
            indegree[it]++;
        }   
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    vector<int> indegree(n,0);
    solve(g,indegree);
    
    for(int it : indegree)
    {
        cout<<it<<" ";
    }
}

/*
5
4
0 2
0 3
1 3
1 4
*/
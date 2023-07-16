#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>>& g,int u,int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}
void dfsRec(vector<vector<int>>& g,vector<bool>& vis,int src)
{
    vis[src] = true;
    // cout<<src<<" ";
    for(int nbr : g[src])
    {
        if(vis[nbr]==false)
        {
            dfsRec(g,vis,nbr);
        }
    }
}
int dfs(vector<vector<int>>& g,int src)
{
    int count = 0;
    vector<bool> vis(g.size(),false);
    for(int i=0;i<g.size();i++)
    {
        if(vis[i]==false)
        {
            dfsRec(g,vis,src);
            count++;
        }
    }
    return count;
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
        addEdge(g,u,v);
    }

    cout<<dfs(g,0);
    return 0;
}
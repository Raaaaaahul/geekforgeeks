#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& g,int u,int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}
bool dfs(vector<vector<int>>& g,vector<bool>& vis,int src,int parent)
{
    vis[src] = true;
    for(int nbr : g[src])
    {
        if(vis[nbr]==false)
        {
            if(dfs(g,vis,nbr,src))
                return true;
        }
        else if(nbr!=parent)
            return true;
    }
    return false;
}
bool cycle(vector<vector<int>>& g,int v)
{
    vector<bool> vis(v,false);
    for(int src = 0;src<v;src++)
    {
        if(vis[src]==false)
        {
            if(dfs(g,vis,src,-1))
            {
                return true;
            }
        }
    }
    return false;
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
    bool ans = cycle(g,n);
    cout<<ans<<endl;
    return 0;
}
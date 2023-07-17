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
    for(auto it:g[src])
    {
        if(!vis[it])
        {
            if(dfs(g,vis,it,src))
                return true;
        }
        else if(it!=parent)
            return true;
    }
    return false;
}

bool detectCycle(vector<vector<int>>& g,int v)
{
    vector<bool> vis(v,false);
    for(int i=0;i<v;i++)
    {
        if(vis[i]==false)
        {
            if(dfs(g,vis,i,-1))
                return true;
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
    bool ans = detectCycle(g,n);
    cout<<ans;
    return 0;
}
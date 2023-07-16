#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>>& g,int u,int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}
void bfs(vector<vector<int>>& g,vector<bool>& vis,int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while(q.empty()==false)
    {
        int u = q.front();
        q.pop();
        cout<<u<<" ";
        for(int nbr : g[u])
        {
            if(vis[nbr]==false)
            {
                vis[nbr] = true;
                q.push(nbr);
            }
        }
    }
}
void dis_bfs(vector<vector<int>>& g)
{
    vector<bool> vis(g.size()+1,false);

    for(int src=0;src<g.size();src++)
    {
        if(vis[src]==false)
        {
            bfs(g,vis,src);
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
        addEdge(g,u,v);
    }

    dis_bfs(g);

    return 0;
}
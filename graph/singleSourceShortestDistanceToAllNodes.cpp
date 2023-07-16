#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>>& g,int u,int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}
void bfs(vector<vector<int>>& g,vector<int>& dist,int src,int v)
{
    vector<bool> vis(v,false);
    vis[src] = true;
    queue<int> q;
    q.push(src);
    while(q.empty()==false)
    {
        int u = q.front();
        q.pop();

        for(int nbr : g[u])
        {
            if(vis[nbr]==false)
            {
                dist[nbr] = dist[u] + 1;
                vis[nbr]=true;
                q.push(nbr);
            }
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
    vector<int> dist(n,INT_MAX);
    int src;
    cout<<"enter source from where traversal will start : "<<endl;
    cin>>src;
    dist[src] = 0;
    bfs(g,dist,src,n);
    for(int i=0;i<dist.size();i++)
    {
        cout<<dist[i]<<" ";
    }
    return 0;
}
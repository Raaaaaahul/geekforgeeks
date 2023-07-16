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
int dis_comp(vector<vector<int>>& g)
{
    int count=0;
    vector<bool> vis(g.size()+1,false);
    for(int i=0;i<g.size();i++)
    {
        if(vis[i]==false)
        {
            bfs(g,vis,i);
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
    cout<<dis_comp(g);
}
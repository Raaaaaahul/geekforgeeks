#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& g,int u,int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}
void printAdjList(vector<vector<int>>& g)
{
   for(int i=0;i<g.size();i++)
   {
        cout<<" node "<<i<<" is connected to :";
        for(int j : g[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
   }
}
void bfs(vector<vector<int>>& g,int src)
{
    vector<bool> vis(g.size()+1,false);
    queue<int> q;
    vis[src] = true;
    q.push(src);
    while(!q.empty())
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
    printAdjList(g);
    cout<<"bfs traversal is : "<<endl;
    bfs(g,2);
    return 0;
}

/*
5
7
0 1
0 2
1 3
1 2
2 3
2 4
3 4
*/
#include<bits/stdc++.h>
using namespace std;

void topologicalSort(vector<vector<pair<int,int>>>& g,vector<bool>& vis,stack<int>& st,int src)
{
    vis[src] = true;
    for(auto it : g[src])
    {
        int nbr = it.first;
        if(vis[nbr]==false)
        {
            topologicalSort(g,vis,st,nbr);
        }
    }
    st.push(src);
}


void shortestPath(vector<vector<pair<int,int>>>& g,int n)
{
   vector<bool> vis(n,false);
    stack<int> st;
   for(int i=0;i<n;i++) 
   {
        if(vis[i]==false)
        {
            topologicalSort(g,vis,st,i);
        }
   }
   vector<int> dist(n,1e9);
   dist[0] = 0;
   while(!st.empty())
   {
        int node = st.top();
        st.pop();
        for(auto it:g[node])
        {
            int v = it.first;
            int w = it.second;

            if(dist[v] > dist[node] +w)
            {
                dist[v] = dist[node] + w;
            }
        }   
   }
   for (int i = 0; i < n; i++) {
        if (dist[i] == 1e9) dist[i] = -1;
      }
      
   for(int i=0;i<n;i++)
   {
    cout<<dist[i]<<" ";
   }
   
}
void display(vector<vector<pair<int,int>>>& g)
{
    for(int i=0;i<g.size();i++)
    {
        
        for(auto it : g[i])
        {
            cout<<i<<" : ";
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> g(n);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    display(g);
    shortestPath(g,n);
   
    return 0;
}
/*
6
7
0 1 2
0 4 1
1 2 3
4 2 2
4 5 4
2 3 6
5 3 1
*/
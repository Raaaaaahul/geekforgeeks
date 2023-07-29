#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int,int>>>& g,int n)
{
    vector<int> dist(n,1e9);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[0] = 0;
    pq.push({0,0});
    while(!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        for(auto it : g[node])
        {
            int nbr = it.first;
            int wt = it.second;
            if(dist[nbr]>dis + wt)
            {
                dist[nbr] = dis + wt;
                pq.push({dist[nbr],nbr});
            }
        }
    }
    for(auto it : dist)
    {
        cout<<it<<" ";
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
    dijkstra(g,n);
    return 0;
}

/*

4
5
0 1 5
0 2 8
1 2 10
1 3 15
2 3 20

*/
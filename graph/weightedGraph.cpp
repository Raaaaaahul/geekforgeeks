#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<pair<int,int>>>& g,int u,int v,int w)
{
    g[u].push_back(make_pair(v,w));
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
        addEdge(g,u,v,w);
    }
    display(g);
    return 0;
}

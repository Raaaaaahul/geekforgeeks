#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>>& g,int src,int dest)
{
    g[src].push_back(dest);
    g[dest].push_back(src);
}
int main()
{
    int vertex;
    cin>>vertex;
    vector<vector<int>> g(vertex);
    int edges;
    cin>>edges;
    while(edges--)
    {
        int src, dest;
        cin>>src>>dest;
        addEdge(g,src,dest);
    }
    for(int i=0;i<g.size();i++)
    {
        cout<<"node "<<i<<" is connected to : ";
        for(int nbr : g[i])
        {
            cout<<nbr<<" ";
        }
        cout<<endl;
    }
    return 0;
}
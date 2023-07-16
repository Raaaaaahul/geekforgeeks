#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
        unordered_map<int,vector<int>> adj;
        void addEdge(int u,int v)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        void printAdj()
        {
            for(auto i:adj)
            {
                cout<<i.first<<" ->";
                for(auto j:i.second)
                {
                    cout<<j<<" ";
                }
                cout<<endl;
            }
        }

};
int main()
{
    int n;
    cout<<"enter the number of nodes : ";
    cin>>n;
    int m;
    cout<<"enter the  number of edges : ";
    cin>>m;
    graph G;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        G.addEdge(u,v);
    }
    G.printAdj();
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n);
    vector<int> indegree(n,0);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        indegree[v]++;
    }

    cout<<"indegree array is as follows : "<<endl;
    for(int it : indegree)
    {
        cout<<it<<" ";
    }
    return 0;
}
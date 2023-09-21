#include<bits/stdc++.h>
using namespace std;
bool is_possible(vector<vector<int>>& g,int n,int m)
{
    queue<pair<int,int>> q;
    vector<vector<int>> vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(g[i][j]==1)
            {
                q.push({i,j});
                vis[i][j]=1;
                break;
            }
        }
    }
    int dx[] = {-1,0,1,0};
    int dy[] = {0,1,0,-1};
    while(q.empty()==false)
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0 and ny>=0 and nx<n and ny<n and (g[nx][ny]==3 or g[nx][ny]==2) and vis[nx][ny]==0)
            {
                if(g[nx][ny]==2)
                {
                    return true;
                }
                vis[nx][ny]=1;
                q.push({nx,ny});
            }
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> g = {{1,3},{3,2}};

    int n = g.size();
    int m = g[0].size();
    cout<<is_possible(g,n,m);
    return 0;
}
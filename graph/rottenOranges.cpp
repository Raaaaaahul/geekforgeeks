#include<bits/stdc++.h>
using namespace std;

int rot(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int freshOranges = 0;
    int Time = 0;
    queue<pair<int,int>> q;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            {
                freshOranges++;
            }
            if(grid[i][j]==2)
            {
                q.push({i,j});
            }
        }
    }
    if(freshOranges==0) return 0;

    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};

    while(q.empty()==false)
    {
        int size = q.size();
        int temp = 0;

        while(q.size()!=0)
        {
            auto p = q.front();
            int x = p.first;
            int y = p.second;

            for(int i=0;i<4;i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 and nx<n and ny>=0 and ny<m and grid[nx][ny]==1)
                {
                    temp++;
                    grid[nx][ny] = 2;
                    q.push({nx,ny});
                }
            }
            size--;
        }
        if(temp!=0)
            Time++;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            {
                Time = 0;
                break;
            }
        }
    }
    return (Time==0) ? -1 : Time;
}

int main()
{
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout<<rot(grid);
    return 0;
}
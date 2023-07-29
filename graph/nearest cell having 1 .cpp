class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> dist(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        while(q.empty()==false)
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            dist[row][col] = step;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and vis[nrow][ncol]==0)
                {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},step+1});
                }
            }
        }
        return dist;
    }
};
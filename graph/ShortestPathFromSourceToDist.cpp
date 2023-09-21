//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0]==0 or A[X][Y]==0)
            return -1;
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        while(pq.empty()==false)
        {
            int dist = pq.top().first;
            int x = pq.top().first.first;
            int y = pq.top().first.second;
            pq.pop();

            if(x==X and y==Y)
            {
                return dist;
            }

            for(int = 0;i<4;i++)
            {
                int nx = dx[i] + x;
                int ny = dy[i] + y;

                if(nx<N and ny<M and nx>=0 and ny>=0 and A[nx][ny]==1)
                {
                    pq.push({dist+1,{nx,ny}});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends
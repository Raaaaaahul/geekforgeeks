#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int evalRPN(vector<vector<int>>& grid){
            int rows = grid.size();
            int cols = grid[0].size();
            int count = 0;
            //increased the count of row vectors in the map
            map<vector<int>,int> mp;
            for(int i=0;i<rows;i++)
            {
                mp[grid[i]]++;
            }
            map<vector<int>,int> col;
            for(int i=0;i<rows;i++)
            {
                vector<int> temp;
                for(int j=0;j<cols;j++)
                {
                    temp.push_back(grid[j][i]);
                }
                col[temp]++;
            }
            // int count = 0;
            for(auto &i : mp)
            {
                if(col.find(i.first)!=col.end())
                {
                    count += (i.second)*col[i.first];
                }
            }
            return count;
        }
};
int main()
{
    Solution obj;
    vector<vector<int>> grid;
    for(int i=0;i<3;i++)
    {
        vector<int> temp;
        for(int j=0;j<3;j++)
        {
            int a;
            cin>>a;
            temp.push_back(a);
        }
        grid.push_back(temp);
    }
    cout<<obj.evalRPN(grid);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int area(vector<int> &v,int n)
{
    stack<int> s;
    int res = 0;
    for(int i=0;i<n;i++)
    {
        while(s.empty()==false and v[s.top()]>=v[i])
        {
            int tp = s.top();
            s.pop();
            int curr = v[tp]*(s.empty()?i:i-st.top()-1);
            res = max(res,curr);
        }
        s.push(i);
        while(s.empty())
        {
            int tp = s.top();
            s.pop();
            int curr = v[tp]*(s.empty()?n:(n-s.top()-1));
            res = max(res,curr);
        }
    }
    return res;
}
int solve(vector<vector<int>>& matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int res = area(matrix[0],cols);
    for(int i=1;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(matrix[i][j]==1)
            {
                matrix[i][j] +=matrix[i-1][j-1];
            }
            res = max(res,area(matrix[i],cols));
        }
    }
    return res;
}
int main()
{
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> solve(vector<int>& v,int n)
{
        // code here
        int i=0;
        int j = i+1;
        vector<vector<int>> ans;
        int idx = i;
        while(j<n)
        {
            if(v[j]>v[idx])
            {
                idx = j;
                j++;
            }
            else if(v[j]<=v[idx])
            {
                if(idx>i)
                {
                    ans.push_back({i,idx});
                }
                i=j;
                j++;
                idx = i;
            }
            if(j==n)
            {
                if(idx>i)
                {
                    ans.push_back({i,idx});
                }
            }
        }
        return ans;
}
int main()
{
    vector<int> v{7,1,5,3,6,4};
    vector<vector<int>> answer = solve(v,v.size());
    for(int i=0;i<answer.size();i++)
    {
        for(int j=0;j<answer[i].size();j++)
        {
            cout<<answer[i][j]<<" ";
        }
    }
    return 0;
}
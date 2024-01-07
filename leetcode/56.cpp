#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<vector<int>>& arr)
{
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++)
    {
        if(ans.empty() or arr[i][0]>ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1],arr[i][1]);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> intervals = {{1,3},{2,4},{2,6},{8,9},{9,10},{9,11},{15,18},{16,17}};
    vector<vector<int>> ans = solve(intervals);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
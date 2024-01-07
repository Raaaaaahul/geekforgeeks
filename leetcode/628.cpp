#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<int> smallestRange(vector<vector<int>>& nums)
    {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i][0],{i,0}});
            maxi = max(maxi,nums[i][0]);
        }
        mini = pq.top().first;
        int start = mini,end = maxi;
        while(pq.empty()==false)
        {
            auto temp = pq.top();
            mini = temp.first;
            int r = temp.second.first;
            int c = temp.second.second;
            pq.pop();

            if(maxi-mini<end-start)
            {
                start = mini;
                end = maxi;
            }
            if(c+1<nums[r].size())
            {
                pq.push({nums[r][c+1],{r,c+1}});
                maxi = max(maxi,nums[r][c+1]);
            }
            else
            {
                break;
            }
        }
        return {start,end};
    }
};

int main()
{
    Solution obj1;
    vector<vector<int>> nums = {{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    vector<int> ans = obj1.smallestRange(nums);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
}
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    static bool comp(pair<string,int>& a,pair<string,int>& b)
    {
        if(a.second==b.second)
        {
            return a.first<b.first;
        }
        else
        {
            return a.second>b.second;
        }
    }

    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        map<string,int> mp;
        for(auto it:words)
        {
            mp[it]++;
        }
        vector<pair<string,int>> temp(mp.begin(),mp.end());
        sort(temp.begin(),temp.end(),comp);

        vector<string> ans;
        for(int i=0;i<k;i++)        
        {
            ans.push_back(temp[i].first);
        }
        return ans;
    }
};

int main()
{
    vector<string> v = {"i","love","leetcode","i","love","coding"};
    int k = 2;
    Solution obj1;
    v = obj1.topKFrequent(v,k);
    for(auto it:v)
    {
        cout<<it<<" ";
    }
    return 0;
}
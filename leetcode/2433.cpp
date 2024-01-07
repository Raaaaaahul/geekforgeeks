#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> res = {pref[0]};
        int len = pref.size();
        for(int i=1;i<len;i++)
        {
            res.push_back(pref[i]^pref[i-1]);
        }
        return res;
    }
};
int main()
{
    Solution obj1;
    vector<int> v = {5,2,0,3,1};
    vector<int> ans = obj1.findArray(v);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
}
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums)
{
    int n = nums.size();
    int count = 0;
    unordered_set<int> st;
    for(auto it:nums)
    {
        st.insert(it);
    }
    for(auto e:st)
    {
        if(st.find(e-1)==st.end())
        {
            int temp = 1;
            while(st.find(e+1)!=st.end())
            {
                temp++;
                e++;
            }
            count = max(count,temp);
        }
    }
    return count;
}

int main()
{
    vector<int> nums{100,4,200,1,3};
    cout<<solve(nums);
    return 0;
}
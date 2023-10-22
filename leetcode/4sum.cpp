<<<<<<< HEAD
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for(int j = i + 1; j < n; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int k = j + 1;
                int l = n - 1;
                while (k < l) {
                    long long sum = static_cast<long long>(nums[i]) + static_cast<long long>(nums[j]) + static_cast<long long>(nums[k]) + static_cast<long long>(nums[l]);
                    if (sum < target) {
                        k++;
                    } else if (sum > target) {
                        l--;
                    } else {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1]) {
                            k++;
                        }
                        while (k < l && nums[l] == nums[l + 1]) {
                            l--;
                        }
=======
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<int>& v,int x)
{
    sort(v.begin(),v.end());
    int n = v.size();
    vector<vector<int>> ans;
    for(int i=0;i<n;i++)
    {
        if(i!=0 and v[i]==v[i-1])
        {
            continue;
        }
        for(int j=i+1;j<n;j++)
        {
            if(j!=i+1 and v[j]==v[j-1])
            {
                continue;
            }
            int k = j+1;
            int l = n-1;
            while(k<l)
            {
                int sum = v[i]+v[j]+v[k]+v[l];
                if(sum<x)
                {
                    k++;
                }
                else if(sum>x)
                {
                    l--;
                }
                else
                {
                    vector<int> temp = {v[i],v[j],v[k],v[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l and v[j]==v[j-1])
                    {
                        j++;
                    }
                    while(k<l and v[l]==v[l+1])
                    {
                        l--;
>>>>>>> 5cf261f04e01cc66de1e7c36f8f5c4174a7545e2
                    }
                }
            }
        }
<<<<<<< HEAD
        return ans;
    }
};
=======
    }
    return ans;
}

int main()
{
    vector<int> v{0,0,2,1,1};
    int k = 3;
    vector<vector<int>> ans = solve(v,k);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();i++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
>>>>>>> 5cf261f04e01cc66de1e7c36f8f5c4174a7545e2

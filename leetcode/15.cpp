#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ThreeSum(vector<int>& v)
{
    int n = v.size();
    vector<vector<int>> ans;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        if(i>0 and v[i]==v[i-1])
        {
            continue;
        }
        int j = i+1;
        int k = n-1;
        while(j<k)
        {
            int sum = v[i]+v[j]+v[k];
            if(sum<0)
            {
                j++;
            }
            else if(sum>0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {v[i],v[j],v[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k and v[j]==v[j-1])
                {
                    j++;
                }
                while(j<k and v[k]==v[k+1])
                {
                    k--;
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> v{-1,0,1,2,-1,-4};
    vector<vector<int>> ans = ThreeSum(v);
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
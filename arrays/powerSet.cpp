#include<bits/stdc++.h>
using namespace std;

void powerSet(vector<int>& v,int n,int idx,vector<vector<int>>& res,vector<int>& ans)
{
    if(idx>=v.size())
        res.push_back(ans);   
        ans.clear();    
        return;

    //exclude
    powerSet(v,n,idx+1,res,ans);

    //include
    ans.push_back(v[idx]);
    powerSet(v,n,idx+1,res,ans);
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<vector<int>> res;
    vector<int> ans;
    powerSet(v,n,0,res,ans);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
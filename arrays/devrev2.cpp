#include<bits/stdc++.h>
using namespace std;
int solve(int n,vector<int> & a)
    {
        if(n==0)
        {
            return 0;
        }
        vector<int> ans;
        ans.push_back(a[0]);
        for(int i=1;i<n;i++)
        {
            if(a[i]>ans.back())
            {
                ans.push_back(a[i]);
            }
            else
            {
                int index=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                ans[index]=a[i];
            }
        }
        return ans.size();
    }
int main()
{
    string s; 
    getline(cin, s);
    int num = 0;
    vector<int> v;
    for(int i = 0; i < s.size(); ++i)
        if(s[i] == ' ')
            v.push_back(num), num = 0;
        else
            num = num*10 + (s[i]-'0');
    v.push_back(num);

    cout<<solve(v.size(),v);

    return 0;
}
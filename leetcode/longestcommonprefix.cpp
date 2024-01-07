#include<bits/stdc++.h>
using namespace std;

string lcp(vector<string>& v)
{
    if(v.empty())
    {
        return "";
    }
    string temp = v[0];
    for(const string& it:v)
    {
        if(it.length()<temp.length())
        {
            temp = it;
        }
    }
    string ans = "";
    for(int i=0;i<temp.length();i++)
    {
        char c = temp[i];
        for(auto s:v)
        {
            if(s[i]!=c)
            {
                return ans;
            }
        }
        ans += c;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    for(auto it:v)
    {
        cout<<it<<" ";
    }
    string ans = lcp(v);
    cout<<ans;
    return 0;
}
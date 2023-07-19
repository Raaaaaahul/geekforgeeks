#include<bits/stdc++.h>
using namespace std;

int solve(string& s)
{
    unordered_map<char,char> mp;
    string original = s;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.length();i++)
    {
        mp[original[i]] = s[i];
    }
    return mp.size();
}
int main()
{
    string s;
    cin >> s;
    int ans = solve(s);
    cout<<ans;
    return 0;
}
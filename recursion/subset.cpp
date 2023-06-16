#include<bits/stdc++.h>
using namespace std;
void solve(string &s,string curr = "", int i=0)
{
    if(i==s.length())
        cout<<s<<endl;
        return;
    solve(s,curr,i+1);
    solve(s,curr + s[i],i+1);
}
int main()
{
    string s = "abc";
    solve(s);
    return 0;
}
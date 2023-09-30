#include<bits/stdc++.h>
using namespace std;
int solve(string s)
{
    if(s.length()==0)
        return -1;
    
    int n = s.length();
    int a = s[0] - '0';
    int idx = 1;
    while(idx<n)
    {
        char p = s[idx];
        idx++;
        if(p=='A')
        {
            a &=(s[idx]-'0');
        }
        else if(p=='B')
        {
            a ||=(s[idx]-'0');
        }
        else
        {
            a ^=(s[idx]-'0');
        }
        idx++;
    }
    return a;
}
int main()
{
    string s;
    cin>>s;
    cout<<solve(s);
    return 0;
}
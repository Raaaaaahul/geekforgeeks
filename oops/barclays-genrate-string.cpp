#include<bits/stdc++.h>
using namespace std;
string solve(string s1,string s2)
{
    string s = "";
    int c = s1[0];
    for(int i=1;i<s1.length();i++)
    {

        if(s1[i]<c)
        {
            c = s1[i];
        }
    }
    for(int i=0;i<s2.length();i++)
    {
        if(s2[i]=='T')
        {
            s+=s1;
        }
        else
        {
            s+=c;
        }
    }
    if(s.length()!=s1.length() + s2.length() -1)
    {
        return "-1";
    }
    return s;

}
int main()
{
    string s1 = "ABCA";
    string s2 = "TFFF";
    cout<<solve(s1,s2);
}
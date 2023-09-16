#include<bits/stdc++.h>
using namespace std;
string solve(string s)
{
    int n = s.length();
    stack<string> st;
    string temp = "";
    for(int i=0;i<n;i++)
    {
        if(s[i]=='.')
        {
            st.push(temp);
            temp="";
        }
        else
        {
            temp+=s[i];
        }
    }
    st.push(temp);
    string res = "";
    while(!st.empty())
    {
        res+=st.top();
        st.pop();
        if(st.empty()==false)
        {
            res+='.';
        }
    }
    return res;
}
int main()
{
    string s = "i.like.this.program.very.much";
    string temp = solve(s);
    cout<<temp;
    return 0;
}
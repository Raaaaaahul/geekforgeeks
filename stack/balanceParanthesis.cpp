    #include<bits/stdc++.h>
using namespace std;
bool matching(char a,char b)
{
    return (( a=='(' && b==')' ) || ( a=='{' && b=='}' ) || (a=='[' && b==']')  );
}
bool checkBalance(string s)
{
    stack<int> st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(' or s[i]=='{' or s[i]=='[')
        {
            st.push(s[i]);
        }
        else if(st.empty()==true)
        {
            return false;
        }
        else if(matching(st.top(),s[i])==false)
        {
            return false;
        }
        else
        {
            st.pop();
        }
    }
    return (st.empty()==true);
}
int main()
{
    string s;
    cin>>s;
    cout<<checkBalance(s);
    return 0;
}
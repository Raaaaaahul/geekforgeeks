#include<bits/stdc++.h>
using namespace std;

string solve(string s)
{
   string temp = "";
   int count = 0;
   for(int i=0;i<s.length();i++)
   {
        if(s[i]=='-')
        {
            count++;
        }
        else
            temp += s[i];
   }
   while(count--)
   {
        temp = '-'+temp;
   }
   return temp;
}
int main()
{
    string s;
    cin>>s;
    cout<<solve(s);
    return 0;
}
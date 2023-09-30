#include<bits/stdc++.h>
using namespace std;

string solve(int n,int num)
{
    unordered_map<int,char> mp;
    char ch = 'A';
    for(int i=0;i<=35;i++)
    {
        if(i<=9)
        {
            mp[i] = i+'0';
        }
        else
        {
            mp[i] = ch;
            ch++;
        }
    }
    string res = "";
    while(num!=0)
    {
        int remi = num%n;
        res = res + mp[remi];
        num = num/n;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
    int n,num;
    cin>>n>>num;
    cout<<solve(n,num);
    return 0;
}
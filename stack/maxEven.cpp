#include<bits/stdc++.h>
using namespace std;

string solve(string str)
{
    int n = str.length();
    int even = INT_MAX,index;
    for(int i=0;i<n-1;i++)
    {
        if((str[i] - '0')%2==0)
        {
            even = (str[i]-'0');
            index = i;
        }
        if(even<=str[n-1]-'0')
        {
            break;
        }
    }
    if(even==INT_MAX)
    {
        return str;
    }
    swap(str[index],str[n-1]);
    return str;
}

int main()
{
    int num;
    cin>>num;
    cout<<solve(to_string(num));
    return 0;
}
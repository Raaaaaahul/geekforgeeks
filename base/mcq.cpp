#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a =40,b=80;
    try
    {
        cin>>a>>b;
        if(b==0)
        {
            throw b;
        }
        else
        {
            cout<<b%a;
        }
    }
    catch(exception e)
    {
        e.what();
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
void TOH(int n,char a,char b,char c)
{
    if(n==0)
        return;
        // cout<<"Move 1 from "<<a<<" to "<<c<<endl;
    
    TOH(n-1,a,c,b);
    cout<<"move "<<n<<" from "<<a<<" to "<<c<<endl;
    TOH(n-1,b,a,c);
}
int main()
{
    int n = 3;
    TOH(n,'a','b','c');
    return 0;
}
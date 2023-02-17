#include<iostream>
using namespace std;
int countbits(int n)
{
    int res=0;
    while(n>0)
    {
        n = (n&(n-1));
        res++;
    }
    return res;
}
int main()
{
    int ans = countbits(16980369);
    cout<<ans;
    return 0;
}  
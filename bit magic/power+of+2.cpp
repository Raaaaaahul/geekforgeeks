#include<iostream>
using namespace std;
bool ispow2(int n)
{
    if(n==0)
        return false;
    return ((n&(n-1))==0);
}
int main()
{
    int ans = ispow2(233);
    return 0;
}
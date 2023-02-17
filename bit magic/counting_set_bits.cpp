#include<iostream>
using namespace std;
int countset(int n)
{
    int res = 0;
    while(n>0)
    {
        if(n%2!=0)
            res++;
        n=n/2;
    }
}
int main()
{
    return 0;
}
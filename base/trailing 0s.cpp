#include<bits/stdc++.h>
using namespace std;

int fact(int num)
{
    if(num==0)
    {
        return 1;
    }
    return num*fact(num-1);
}

int trial(int num)
{
    long long int res = 0;
    long long int fx = fact(num);
    while(fx%10==0)
    {
        res++;
        fx = fx/10;
    }
    return res;
}
int main()
{
   long int num = 100;
   long int ans = trial(num);
    cout<<ans;
    return 0;
}
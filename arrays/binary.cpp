#include<bits/stdc++.h>
using namespace std;
int binaryToDecimal(int n)
{
    int dec_num = 0 ;
    int power = 0 ;
    while(n>0)
    {
        if(n%10 == 1)
        { 
            dec_num += (1<<power) ;
        }
        power++;
        n = n / 10 ;
    }
      return dec_num ;
}
int solve(int num)
{
    int count = 0;
    while(num>0)
    {
        if(num%2!=0)
        {
            count++;
            num = num-1;
        }
        else
        {
            count++;
            num = num/2;
        }
    }
    return count;
}
int main()
{
    int num;
    cin>>num;
    num = binaryToDecimal(num);
    cout<<solve(num);
    return 0;
}
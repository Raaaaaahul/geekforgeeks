#include<bits/stdc++.h>
using namespace std;

int solve(int num1,int num2)
{
    int carry = 0,sum,p,q,count=0;
    while((num1!=0) and (num2!=0))
    {
        p = num1%10;
        q = num2%10;
        sum = carry+p+q;
        if(sum>9)
        {
            carry=1;
            count++;
        }
        else
        {
            carry = 0;
        }
        num1 = num1/10;
        num2 = num2/10;
    }
    while(num1!=0)
    {
        p = num1%10;
        sum = carry+p;
        if(sum>9)
        {
            carry = 1;
            count++;
        }
        else
        {
            carry = 0;
        }
        num1 = num1/10;
    }

    while(num2!=0)
    {
        q = num2%10;
        sum = q + carry;
        if(sum>9)
        {
            carry = 1;
            count++;
        }
        else
        {
            carry = 0;
        }
        num2 = num2/10;
    }


    return count;
}

int main()
{
    int num1,num2;
    cin>>num1>>num2;
    cout<<solve(num1,num2);
    return 0;
}
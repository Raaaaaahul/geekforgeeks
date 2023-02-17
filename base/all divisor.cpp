#include<iostream>
using namespace std;
void printDivisor(int n)
{
    int i;
    for(i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            cout<<i<<" ";
        }
    }
    for(;i>=1;i--)
        {
            if(n%i==0)
            {
                cout<<(n/i)<<" ";
            }
        }
}
int main()
{
    int num = 15;
    printDivisor(num);
    return 0;
}
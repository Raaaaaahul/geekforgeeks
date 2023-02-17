#include<bits/stdc++.h>
using namespace std;
bool palindrome(int n)
{
    int rev = 0;
    int temp = n;
    //reverse of the number
    //and then comparing the number
    while(temp!=0)
    {
        int lastDigit = temp%10;
        rev = rev*10+lastDigit;
        temp = temp/10;
    } 
    return (rev==n);
}
int main()
{
    int num = -121;
    int ans = palindrome(num);
    cout<<ans;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int countDigit(int n)
{
    return floor(log10(n)+1);
}
int main()
{
    int num = 1231;
    int ans = countDigit(num);
    cout<<ans;
    return 0;
}
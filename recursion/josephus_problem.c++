#include<bits/stdc++.h>
using namespace std;
int jos(int n,int k)
{
    if(n==1)
{
    return 0;
}
    return (jos(n-1,k)+k)%n;
    //every iteration we are reducing a person so each recursive call function is called for one less value of N
    //since k i.e killing iterator doesnot changes we are keeping that as constant
    //after every recursive call the position of the people changes by k so we are adding K
    //finally we are doing modular divison by N because we want the results to be in the range of 0 to N
}
int main()
{
    int ans = jos(5,3);
    cout<<ans;
    return 0;
}
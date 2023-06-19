#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int num,ans=0;
        cin>>num;
        ans +=2*num;
        num = num-1;
        while(num>=1)
        {
            ans+=num;
            num--;
        }
        cout<<ans<<endl;
    }
    return 0;
    
}
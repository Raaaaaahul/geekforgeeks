#include<bits/stdc++.h>
using namespace std;
#define B 32
int solve(int arr[],int n)
{
    int ans = 0;
    for(int i=0;i<B;i++)
    {
        int cset=0;
        for(int j=0;j<n;j++)
        {
            if(arr[j]&(1<<i))
                cset++;
        }
    
        int subset = (1<<cset) - 1;
        subset = (subset*(1<<i));
        ans+=subset;
    }
    return ans;
}
int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        int size;
        cin>>size;
        int arr[size];
        for(int i=0;i<size;i++)
        {
            cin>>arr[i];
        }
        cout<<solve(arr,size)<<endl;
    }
    return 0;
}
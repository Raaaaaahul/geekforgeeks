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
    
    int arr[] = { 1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << solve(arr, size);
    return 0;
}
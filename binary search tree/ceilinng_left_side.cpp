#include<bits/stdc++.h>
using namespace std;
void prevGreater(int arr[],int n)
{
    set<int> s;
    for(int i=0;i<n;i++)
    {
        auto it = s.lower_bound(arr[i]);
        if(it==s.end())
        {
            cout<<" -1"<<" ";
        }
        else
        {
            cout<<(*it)<<" ";
        }
        s.insert(arr[i]);
    }
}
int main()
{
    int arr[] = { 10, 5, 11, 10, 20, 12 };
    int n = sizeof(arr) / sizeof(arr[0]);
    prevGreater(arr, n);
    return 0;
}
issor
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> arr)
{
    int j=1;
    for(int i=0;i<arr.size()-1;i++)
    {
        if(arr[i]!=arr[i+1])
        {
            arr[j] = arr[i+1];
            j++;
        }
    }
    return j;
}
int main()
{
    vector<int> arr = {10,10,10,20};
    int ans = solve(arr);

    cout<<ans; 
    cout<<endl;
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
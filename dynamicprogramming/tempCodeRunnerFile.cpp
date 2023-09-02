#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int>& arr,int n,long long sum)
{
    int i=0;
    int j=0;

    int currSum = 0;
    while(j<n)
    {
        currSum+=arr[j];

        if(currSum>sum)
        {
            if(i<j and currSum> sum)
            {
                currSum-=arr[i];
                i++;
            }
        }
        if(currSum == sum)
        {
            return {i+1,j+1};
        }
        else
        {
            j++;
        }
    }
    return {-1};
}
int main()
{
    vector<int> arr{1,2,3,7,5};
    int n = arr.size();
    long long sum = 12;
    vector<int> ans = solve(arr,n,sum);
    for(auto it : ans)
    {
        cout<<it<<" ";
    }
    return 0;
}
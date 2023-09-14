#include<bits/stdc++.h>
using namespace std;
long long solve(vector<int> arr)
{
    long long left_max=0,right_max=0,res=0;
    long long lptr = 0;
    long long rptr=arr.size()-1;

    while(lptr<=rptr)
    {
        if(arr[lptr]<=arr[rptr])
        {
            if(left_max<=arr[lptr])
            {
                left_max=arr[lptr];
            }
            else
            {
                res += left_max - arr[lptr];
            }
            lptr++;
        }
        else
        {
            if(right_max<=arr[rptr])
            {
                right_max = arr[rptr];
            }
            else
            {
                res+=right_max - arr[rptr];
            }
            rptr--;
        }
    }
    return res;
}
int main()
{
    vector<int> arr{3,0,0,2,0,4};
    cout<<solve(arr);
    return 0;
}
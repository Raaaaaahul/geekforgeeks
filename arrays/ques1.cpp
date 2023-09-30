#include<bits/stdc++.h>
using namespace std;

int calculate(int r,int u,int n,vector<int>& arr)
{
    int count = 0;
    int food = 0;
    for(int i=0;i<n;i++)
    {
        if(food<r*u)
        {
            count++;
            food+=arr[i];
        }
        else
        {
            break;
        }
    }
    if(r*u>food)
    {
        return 0;
    }
    return count;

}
int main()
{
    int r = 7;
    int unit = 2;
    int n = 8;
    vector<int> arr{2,8,3,5,7,4,1,2};
    cout<<calculate(r,unit,n,arr);
    return 0;
}
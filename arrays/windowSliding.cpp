#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>& v,int n,int k)
{
    int curr_sum = 0;

    for(int i=0;i<k;i++)
    {
        curr_sum+=v[i];
    }
    int max_sum = curr_sum;
    for(int i=k;i<n;i++)
    {
        curr_sum +=(v[i] - v[i-k]);
        max_sum = max(curr_sum,max_sum);
    }
    cout<<max_sum;
}
bool isSubSum(vector<int>& v,int n,int sum)
{
    int curr_sum = v[0],s=0;
    for(int e=1;e<n;e++)
    {
        while(curr_sum>sum && s<e-1)
        {
            curr_sum-=v[s];
            s++;
        }
        if(curr_sum==sum)
            return true;
        if(e<n)
        {
            curr_sum+=v[e];
        }
    }
    return (curr_sum==sum);
}
int main()
{   
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    solve(v,n,k);
    cout<<endl;
    int sum = 33;
    cout<<isSubSum(v,n,sum);
    return 0;
}
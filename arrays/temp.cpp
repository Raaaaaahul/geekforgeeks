#include<bits/stdc++.h>
using namespace std;
int maxSubArraySum(vector<int>& v,int n)
{
    int res = v[0];
    int maxEnding = v[0];
    for(int i=1;i<n;i++)
    {
        maxEnding = max(maxEnding + v[i],v[i]);
        res = max(res,maxEnding);
    }
    return res;
}
int maxLengthEvenOddSubArray(vector<int>& v,int n)
{
    int res = 1;
    int curr = 1;

    for(int i=1;i<n;i++)
    {
        
        if(v[i-1]%2!=0)
        {
            if(v[i]%2!=0)
            {
                curr=1;
            }
            else
            {
                curr++;
                res = max(curr,res);
            }
        }
        if(v[i-1]%2==0)
        {
            if(v[i]%2==0)
            {
                curr=1;
            }
            else
            {
                curr++;
                res = max(curr,res);
            }
        }
    }
    return res;

}
int main()
{
    int size;
    cin>>size;
    vector<int> v(size);
    cout<<"enter only ones and zeroes"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>v[i];
    }
    // int ans = maxSubArraySum(v,size);
    int ans = maxLengthEvenOddSubArray(v,size);
    cout<<ans;
    return 0;
}
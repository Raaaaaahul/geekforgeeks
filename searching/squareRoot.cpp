#include<bits/stdc++.h>
using namespace std;
int sqs(int x)
{
    int low = 1,high = x,ans = -1;
    while(low<=high)
    {
        int mid = (low+mid)/2;
        int mSq = mid*mid;
        if(mSq==x)
        {
            return mid;
        }
        else if(mSq>x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid+1;
            ans = mid;
        }
    }
    return ans;
}
int main()
{
    int num;
    cin>>num;
    cout<<sqs(num);
    return 0;
}
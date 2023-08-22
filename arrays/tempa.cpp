#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> pq;
    vector<int> v{1,2,3,4,6,8};
    for(auto it:v)
    {
        pq.push(it);
    }
    int k = 2;
    int ans = 0;
    for(int i=0;i<k;i++)
    {
        int ans = pq.top();
        pq.pop();
    }
    cout<<ans;
    return 0;
}
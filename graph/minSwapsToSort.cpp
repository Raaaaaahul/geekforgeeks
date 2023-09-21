#include<bits/stdc++.h> 
using namespace std;
int solve(vector<int>& v,int n)
{
    vector<pair<int,int>> mp(n);
    for(int i=0;i<n;i++)
    {
        mp[i].first = v[i];
        mp[i].second = i;
    }   

    sort(mp.begin(),mp.end());
    vector<int> vis(n,0);
    int answer = 0;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==1 or mp[i].second==i)
        {
            continue;
        }
        int j=i;
        int cycleSize = 0;
        while(vis[j]==0)
        {
            vis[j]=1;
            j = mp[j].second;
            cycleSize++;
        }
        if(cycleSize>0)
        {
            answer+=cycleSize-1;
        }
    }
    return answer;

}
int main()
{
    vector<int> v = {2, 8, 5, 4};
    int n = v.size();
    cout<<solve(v , n)<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
void bubsort(vector<int>& v)
{
    int n = v.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if (v[j]>v[j+1])
            swap(v[j],v[j+1]);
        }
        
    }
}
int main()
{
    vector<int> v{89,23,12,30,88,77};
    bubsort(v);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
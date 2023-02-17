#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> arr)
{
    int j=0;
    for(int i=0;i<arr.size()-1;i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[i],arr[j]);
            j++;
        }
    }
    return arr;
}
int main()
{
    vector<int> arr ={8,5,0,10,0};
    vector<int> ans = solve(arr);
    for(auto i = ans.begin();i!=ans.end();i++)
    {
        cout<<*i<<" ";
    }
    return 0;
}
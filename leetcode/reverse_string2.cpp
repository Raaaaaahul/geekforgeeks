#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    string solve(string s,int k)
    {
        int n = s.length();
        for(int i=0;i<n;i+=2*k)
        {
            string str = s.substr(i,k);
            reverse(str.begin(),str.end());
            s.replace(i,k,str);
        }
        return s
    }
};
int main()
{
    Solution obj1;
    string sol = obj1.solve("abcdefg",2);
    cout<<sol;
    return 0;
}
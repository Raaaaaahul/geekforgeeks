<<<<<<< HEAD
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
//LEETCODE 541 COPY ONLY THE CLASS AND THE CHANGE THE SOLVE TO PREDEFINED FUNCION
int main()
{
    Solution obj1;
    string sol = obj1.solve("abcdefg",2);
    cout<<sol;
    return 0;
=======
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
//LEETCODE 541 COPY ONLY THE CLASS AND THE CHANGE THE SOLVE TO PREDEFINED FUNCION
int main()
{
    Solution obj1;
    string sol = obj1.solve("abcdefg",2);
    cout<<sol;
    return 0;
>>>>>>> 33f68f6c19295d22fdd6343e1466741a459301ac
}
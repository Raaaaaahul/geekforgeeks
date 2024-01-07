//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        vector<int> mp(26,-1);
        int mini = 1e9;
        for(int i=0;i<str.length();i++)
        {
            int idx = str[i] - 'a';
            if(mp[idx]==-1)
            {
                mp[idx] = i;
            }
        }
        for(auto it:patt)
        {
            int idx = it-'a';
            if(mp[idx]!=-1)
            {
                mini = min(mini,mp[idx]);
            }
        }
        if(mini!=1e9) return mini;
        return -1;

    }
};

//{ Driver Code Starts.

int main()
{
	int t=1;
    // cin>>t;
    while(t--)
    {
        string str = "geeksforgeeks";
        string patt = "set";
        // cin>>str;
        // cin>>patt;
        Solution obj;
        cout<<obj.minIndexChar(str, patt)<<endl;
    }
	return 0;
}

// } Driver Code Ends
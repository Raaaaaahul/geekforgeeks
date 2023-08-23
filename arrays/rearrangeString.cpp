#include<bits/stdc++.h>
using namespace std;
string solve(string s)
{
    vector<int> freq(26,0);
    for(char ch:s)
    {
        freq[ch-'a']++;
    }
    //finding the majority element
    int letter = 0;
    int maxCount = 0;
    for(int i=0;i<freq.size();i++)
    {
        if(freq[i]>maxCount)
        {
            maxCount = freq[i];
            letter = i;
        }
    }

    //checking if the freq of majority  element is greater than  half  of length of s 
    if(maxCount>(s.length()+1)/2)
        return "";
    //filling up the even positions with  the majority element
    int idx = 0;
    string ans = s;
    while(freq[letter]!=0)
    {
        ans[idx] = char(letter + 'a');
        freq[letter]--;
        idx+=2;
    }
    //filling up the remaining places with remaining  characters
    for(int i=0;i<freq.size();i++)
    {
        while(freq[i]>0)
        {
            if(idx>=s.length())
                idx=1;
            
            ans[idx] = char(i+'a');
            idx+=2;
            freq[i]--;
        }
    }
    return ans;
}
int main()
{
    string s;
    cin>>s;
    cout<<solve(s);   
    return 0;
}
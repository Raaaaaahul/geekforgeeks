
#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string str)
{
	int len = str.length();
	if (len == 1)
		return true;

	int start = 0;
	int end = len-1;
    
	while (end > strstart) {
		if (str[start] != str[end])
			return false;
		
		start++;
		end--;     
	}

	return true;
}


int noOfAppends(string s)
{
	if (isPalindrome(s))
		return 0;
	s.erase(s.begin());

	return 1 + noOfAppends(s);
}
int main()
{
	string s = "abede";
	cout << noOfAppends(s) << endl;
	return 0;
}
  
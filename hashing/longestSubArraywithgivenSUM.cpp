
#include <bits/stdc++.h>
using namespace std;

int lenOfLongSubarr(int arr[],int n,int k)
{
	unordered_map<int, int> um;
	int sum = 0, maxLen = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (sum == k)
			maxLen = i + 1;

		if (um.find(sum) == um.end())
			um[sum] = i;


		if (um.find(sum - k) != um.end()) {

			if (maxLen < (i - um[sum - k]))
				maxLen = i - um[sum - k];
		}
	}

	// required maximum length
	return maxLen;
}

// Driver Code
int main()
{
	int arr[] = {1,-1,1,1,1,-1,-1};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 0;
	cout << "Length = "
		<< lenOfLongSubarr(arr, n, k);
	return 0;
}

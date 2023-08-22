// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find maximum length
// of subsequence having XOR of
// adjacent elements equal to K
int xorSubsequence(int a[], int n, int k)
{

// Store maximum length of subsequence
int ans = 0;

// Stores the dp-states
int dp[n] = {0};

// Base case
dp[0] = 1;

// Iterate over the range [1, N-1]
for (int i = 1; i < n; i++) {

	// Iterate over the range [0, i - 1]
	for (int j = i - 1; j >= 0; j--) {

	// If arr[i]^arr[j] == K
	if ((a[i] ^ a[j]) == k)

		// Update the dp[i]
		dp[i] = max(dp[i], dp[j] + 1);
	}

	// Update the maximum subsequence length
	ans = max(ans, dp[i]);
	dp[i] = max(1, dp[i]);
}

// If length of longest subsequence
// is less than 2 then return 0
return ans >= 2 ? ans : 0;
}

// Driver Code
int main()
{

// Input
int arr[] = {1,3,2};
int K = 1;
int N = sizeof(arr) / sizeof(arr[0]);

// Print the length of longest subsequence
cout << xorSubsequence(arr, N, K);
return 0;
}

// This code is contributed by Dharanendra L V

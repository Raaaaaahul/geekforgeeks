vector<int> max_of_subarrays(int *arr, int n, int k)
{
    vector<int> ans;  // Create a vector to store the maximum values of subarrays.
    deque<int> dq;    // Create a deque (double-ended queue) to maintain elements of the current subarray.
    int maxi = INT_MIN;  // Initialize a variable maxi to store the maximum value seen so far.
    int i=0,j=0;     // Initialize two pointers i and j to represent the start and end of the current subarray.

    // Start a loop to iterate through the array.
    while(j<n)
    {
        // While the deque is not empty and the last element in the deque is smaller than the current array element (arr[j]),
        // remove the last element from the deque as it cannot be the maximum of the current subarray.
        while(dq.empty()==false and dq.back()<arr[j])
        {
            dq.pop_back();
        }
        
        // Push the current array element (arr[j]) into the deque.
        dq.push_back(arr[j]);
        
        // If the size of the current subarray (j - i + 1) is equal to k (the desired subarray size),
        // it means we have processed a complete subarray, so we can add the maximum element of this subarray to the result vector (ans).
        if(j-i+1==k)
        {
            ans.push_back(dq.front()); // Add the maximum element of the current subarray to the ans vector.
            
            // If the maximum element of the current subarray (front element of deque) is the same as the element we are about to remove (arr[i]),
            // it means we need to remove it from the deque because it's no longer part of the current subarray.
            if(dq.front()==arr[i])
            {
                dq.pop_front();
            }
            i++; // Increment the start pointer to move to the next subarray.
        }
        j++; // Increment the end pointer to process the next element in the array.
    }
    
    return ans; // Return the vector containing maximum values of all subarrays of size k.
}

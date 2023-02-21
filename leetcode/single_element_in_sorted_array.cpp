class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0,high = nums.size() - 1;
        while(low<high)
        {
            int mid = (low+high)/2;
            if(mid%2==1)
                mid = mid-1;
            
            if(nums[mid]!=nums[mid+1])
                high = mid;
            else
                low = mid+2;
        }
        return nums[low];
    }
};
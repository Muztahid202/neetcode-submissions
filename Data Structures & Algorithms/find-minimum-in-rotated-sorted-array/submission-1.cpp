class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0;
        int high = nums.size()-1;
        int minVal = 100000;

        while(low <= high){
            int mid = (low + high)/2;
            //left half is sorted
            if(nums[low] <= nums[mid]){
                minVal = min(minVal, nums[low]);
                low = mid + 1;
            }
            //right half is sorted 
            else{
                minVal = min(minVal, nums[mid]);
                high = mid - 1;
            }
       }
       return minVal;
    }
};

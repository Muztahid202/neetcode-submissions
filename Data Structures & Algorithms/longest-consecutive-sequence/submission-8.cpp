class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //when no element then the len is 0
        if(nums.empty()) return 0;

        vector<int> copyNums;
        for(int num: nums){
            copyNums.push_back(num);
        }
        //sort the array
        sort(copyNums.begin(), copyNums.end());
        int count = 1;
        int consLen = 1;

        for(int i = 1; i < copyNums.size(); i++)
        {
            if(copyNums[i]-copyNums[i-1] == 1) count++;
            if(count > consLen) consLen = count;
            if(copyNums[i] - copyNums[i-1] > 1) count = 1;
        }
        return consLen;

    }
};

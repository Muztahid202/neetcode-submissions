class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 0) nums[i] = 0;
        }

        int length = nums.size();

        for(int i = 0; i < length; i++)
        {
            int index = abs(nums[i]) - 1;
            if(index >= 0 && index < length){
                if(nums[index] > 0)
                {
                    nums[index] *= -1;
                }
                else if(nums[index] == 0)
                {
                    nums[index] = (length + 1) * -1;
                }
            }
        }

        for(int i = 1; i < length+1; i++)
        {
            int index = i - 1;
            if(nums[index] >= 0) return i;
        }

        return length + 1;
        
    }
};
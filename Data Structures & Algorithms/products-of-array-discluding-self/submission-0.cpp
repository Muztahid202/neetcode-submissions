class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int mult = 1;

        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if(i!=j){ 
                    mult *= nums[j];
                }
            }
            res[i] = mult;
            mult = 1;
        }

        return res;

    }
};

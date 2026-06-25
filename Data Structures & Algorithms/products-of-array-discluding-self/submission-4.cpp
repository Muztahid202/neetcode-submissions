class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        res.push_back(1);
        int mul = 1;
        //calculating the prefixes
        for(int i = 0; i < nums.size()-1; i++){
            mul *= nums[i];
            res.push_back(mul);
        }
        mul = 1;
        //multiplying with the post fixes
        for(int j = nums.size()-1; j >= 1; j--)
        {
            mul *= nums[j]; 
            res[j-1] *= mul;
        }
        return res;

    }
};

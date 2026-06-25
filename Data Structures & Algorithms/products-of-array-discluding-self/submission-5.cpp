class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,1); 
        
        //calculating the prefixes
        for(int i = 1; i < n; i++){
            res[i] = res[i-1] * nums[i-1];
        }
        int mul = 1;
        //multiplying with the post fixes
        for(int j = n-1; j >= 1; j--)
        {
            mul *= nums[j]; 
            res[j-1] *= mul;
        }
        return res;

    }
};

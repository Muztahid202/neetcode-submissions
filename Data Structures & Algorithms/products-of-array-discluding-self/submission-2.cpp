class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        int pref = 1;
        int post = 1;

        //O(n)
        for(int i = 1; i < nums.size(); i++)
        {
           pref *= nums[i-1];
           res[i] = pref;
        }

      //O(n)
        for(int j = nums.size()-2; j >= 0; j--)
        {
            post *= nums[j+1];
            res[j] *= post;
        }

        return res;

    }
};

//TC = O(n)
//SC = O(n) for op

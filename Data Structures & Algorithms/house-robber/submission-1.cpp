class Solution {
public:
    int dfs(vector<int>& nums, int idx, vector<int>& dp){
        if(idx == 0) return nums[idx];
        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];

        //picking the idx
        int pick = nums[idx] + dfs(nums, idx - 2, dp);
        //not picking the idx
        int notPick = 0 + dfs(nums, idx - 1, dp);
        dp[idx] = max(pick, notPick);
        return dp[idx];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return dfs(nums, n-1, dp);
    }
};
//memoization
class Solution {
public:
    int dfs(vector<int>& nums, int idx, vector<int>& dp){
        if(idx == 0) return nums[0];
        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];

        int pick = nums[idx] + dfs(nums, idx-2, dp);
        int notPick = dfs(nums, idx-1, dp);
        dp[idx] = max(pick, notPick);
        return dp[idx];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        //dp array
        vector<int> dp(n-1, -1);
        //the array which will contain each element except the last one
        vector<int> a(n-1);
        //the array which will contain each element except the first one
        vector<int> b(n-1);
        for(int i = 0; i < n-1; i++){
            a[i] = nums[i];
            b[i] = nums[i+1];
        }
        
        int exceptLast = dfs(a, n-2, dp);
        //reset the dp array
        for(int j = 0; j < n-1; j++){
            dp[j] = -1;
        }
        int exceptFirst = dfs(b, n-2, dp);
        return max(exceptFirst, exceptLast);
    }
};

//memoization
//TC = O(n)
//Sc = O(n)

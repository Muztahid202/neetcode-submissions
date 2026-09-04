class Solution {
public:
    int dfs(int n, vector<int>& dp){
        if(n == 0 || n == 1) return 1;
        if(dp[n] != -1) return dp[n];

        dp[n] = dfs(n-1, dp) + dfs(n-2, dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return dfs(n, dp);
    }
};

//Memoization
//TC = O(n)
//SC = O(n)
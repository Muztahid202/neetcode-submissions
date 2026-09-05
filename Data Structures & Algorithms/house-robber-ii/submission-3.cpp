class Solution {
public:
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
        //considering seq 0...n-1
        dp[0] = a[0];

        for(int i = 1; i < n-1; i++){
            if(i > 1){
                dp[i] = max(a[i] + dp[i-2], dp[i-1]);
            }else dp[i] = max(a[i], dp[i-1]);
        }

        int exceptLast = dp[n-2];

        dp[0] = b[0];
        for(int i = 1; i < n-1; i++){
            if(i > 1){
                dp[i] = max(b[i] + dp[i-2], dp[i-1]);
            }else dp[i] = max(b[i], dp[i-1]);
        }

        int exceptFirst = dp[n-2];

        return max(exceptLast, exceptFirst);

    }
};

//tabular
//TC = O(n)
//Sc = O(n)

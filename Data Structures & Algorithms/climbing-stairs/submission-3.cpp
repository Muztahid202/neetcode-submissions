class Solution {
public:
    int climbStairs(int n) {
        int prev = 1;
        int prev2 = 1;
        int curri = -1;
        for(int  i = 2; i <= n; i++){
            curri = prev + prev2;
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};
//Space optimized no dp array needed
//TC = O(n)
//SC = O(1)
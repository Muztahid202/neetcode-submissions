class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        //the array which will contain each element except the last one
        vector<int> a(n-1);
        //the array which will contain each element except the first one
        vector<int> b(n-1);
        for(int i = 0; i < n-1; i++){
            a[i] = nums[i];
            b[i] = nums[i+1];
        }
        //considering seq 0...n-1
        int prev = a[0];
        int prev2 = 0;
        int curr = -1;

        for(int i = 1; i < n-1; i++){
            if(i > 1){
                curr = max(a[i] + prev2, prev);
            }else curr = max(a[i], prev);
            prev2 = prev;
            prev = curr;
        }

        int exceptLast = prev;

        prev = b[0];
        prev2 = 0;

        for(int i = 1; i < n-1; i++){
            if(i > 1){
                curr = max(b[i] + prev2, prev);
            }else curr = max(b[i], prev);
            prev2 = prev;
            prev = curr;
        }

        int exceptFirst = prev;

        return max(exceptLast, exceptFirst);

    }
};

//tabular
//TC = O(n)
//Sc = O(n)

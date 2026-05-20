class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        //O(n^2)
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i; j < nums.size(); j++){
                 sum += nums[j];
                 if(sum == k) count++;
            }
            sum = 0;
        }
        return count;
        
    }
};

//TC = O(n^2)
//SC = O(1)
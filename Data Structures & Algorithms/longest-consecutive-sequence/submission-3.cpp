class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> a(nums.begin(), nums.end());

       int maxCount = 0;

       for(int num : nums)
       {
            //check if the num is the start of the possible longest subsequence
            if(!a.count(num-1)){
                int current = num;
                int count = 1;

                while(a.count(current+1))
                {
                    count++;
                    current += 1; 
                }
                
                maxCount = max(count, maxCount);
            }
       }

       return maxCount;
    }
};

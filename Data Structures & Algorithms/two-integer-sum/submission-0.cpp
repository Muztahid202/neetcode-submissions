class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> a;

        for(int i = 0; i < nums.size(); i++)
        {
            a[nums[i]] = i;
        } 

        for(int j = 0; j < nums.size(); j++)
        {
            int diff = target - nums[j];

            auto it = a.find(diff);
            if(it != a.end() && it->second != j)
                return {j,it->second};
        }
    }
};

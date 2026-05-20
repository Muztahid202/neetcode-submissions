class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> a;

        for(int i = 0; i < nums.size(); i++)
        {
            a[nums[i]]++;
        }

        for(auto pair : a)
        {
            if(pair.second > ceil(double(nums.size()/2))) return pair.first;
        }

        
    }
};
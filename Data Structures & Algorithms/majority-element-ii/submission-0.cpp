class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        unordered_map<int, int> a;
        vector<int> b;

        int count = ceil(nums.size()/3);

        for(int num : nums)
        {
            a[num]++;
        }

        for(auto pair : a)
        {
            if(pair.second > count)
            {
                b.push_back(pair.first);
            }
        }

        return b;
        
    }
};
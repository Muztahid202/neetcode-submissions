class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        unordered_map<int, int> a;
        vector<int> b;

        int count = nums.size()/3;

        //O(n)
        for(int num : nums)
        {
            a[num]++;
        }

        //worst case : O(n)
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

//TC = O(n)
//SC = O(n)
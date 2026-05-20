class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int, int> count;
       //special array
       vector<vector<int>> bucket(nums.size()+1);
       vector<int> ans;

        for(int num : nums)
        {
            count[num]++;
        }

        for(auto pair : count)
        {
            bucket[pair.second].push_back(pair.first);
        }

        
            
        for(int i = nums.size(); i>=0; i--)
        {
            for(int num : bucket[i])
            {
                ans.push_back(num);
            }
            if(ans.size() == k) return ans;
        }

        return ans;


    }
};



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        vector<vector<int>> buckets(nums.size()+1);
        vector<int> res;
        //count(O(n))
        for(int num : nums){
            countMap[num]++;
        }

        //filling the bucket
        for(auto &p : countMap){
            buckets[p.second].push_back(p.first);
        }

        for(int i = buckets.size()-1; i >=0; i--)
        {
            for(int num : buckets[i]){
                res.push_back(num);
                if(res.size()==k) return res;
            }
        }
        return res;
    }
};

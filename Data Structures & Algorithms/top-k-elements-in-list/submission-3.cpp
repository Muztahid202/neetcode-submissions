class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        vector<int> res;
        //count(O(n))
        for(int num : nums){
            countMap[num]++;
        }
        //for sorting
        //O(n)
        vector<pair<int,int>>v(countMap.begin(), countMap.end());
        //O(nlogn)
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        //O(k)
        for(int i = 0; i < k; i++)
        {
            res.push_back(v[i].first);
        }
        return res;
    }
};

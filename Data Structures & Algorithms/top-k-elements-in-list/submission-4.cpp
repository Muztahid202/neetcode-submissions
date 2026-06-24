class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        vector<vector<int>> a(nums.size()+1);
        vector<int> res;
        //count(O(n))
        for(int num : nums){
            countMap[num]++;
        }

        //filling the bucket
        for(auto &p : countMap){
            a[p.second].push_back(p.first);
        }

        for(int i = a.size()-1; i >=0; i--)
        {
            for(int j = 0; j<a[i].size(); j++){
                res.push_back(a[i][j]);
                if(res.size()==k) return res;
            }
        }
        return {};
    }
};

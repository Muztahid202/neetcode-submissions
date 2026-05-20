class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i : nums){
            m[i]++;
        }
        vector<pair<int,int>> copyMap(m.begin(), m.end());
        sort(copyMap.begin(), copyMap.end(),[](const pair<int,int> &a, 
                                    const pair<int,int> &b){
        return a.second > b.second;                
        });
        vector<int> res;
        for(int j = 0; j < k; j++)
        {
            res.push_back(copyMap[j].first);
        }
        return res;

    }
};

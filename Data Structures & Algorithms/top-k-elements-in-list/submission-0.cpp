class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> a;
        vector<int> ans;

        for(int num: nums)
        {
            a[num]++;
        }

        vector<pair<int, int>> b(a.begin(), a.end());

        //sort them
        sort(b.begin(), b.end(), [](const pair<int,int> &c, const pair<int,int> &d){
            return c.second>d.second;
        });

        int count = 0;
        for(auto [key,value] : b)
        {
            if(count == k) return ans;
            ans.push_back(key);
            count++;
        }

        return ans;
        
    }
};

//TC O(n)
//SC O(n)

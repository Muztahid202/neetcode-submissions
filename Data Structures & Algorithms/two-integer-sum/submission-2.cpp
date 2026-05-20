class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i = 0; i< nums.size(); i++)
        {
            int req = target - nums[i];
            if(m.find(req) == m.end()){
                m.insert({nums[i], i});
            }
            else return{m[req],i};
        }
        return {0,0};
    }
};

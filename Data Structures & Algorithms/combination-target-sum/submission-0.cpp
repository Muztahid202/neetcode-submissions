class Solution {
public:
void combinationSumHelper(vector<int>& candidates, int index, int target, vector<int> &combination, vector<vector<int>>& res){
        //we have found a valid combination
        if(target == 0){
            res.push_back(combination);
            return;
        }
        //we have reached the end of the recursion tree
        if(index == candidates.size()){
            if(target == 0) res.push_back(combination); //that's also a valid combination
            return;
        }

        if(candidates[index] <= target){
            combination.push_back(candidates[index]);
            //picking up the element in the combination
            combinationSumHelper(candidates, index, target-candidates[index], combination, res);
            combination.pop_back(); //will remove the added element while backtracking 
        }
        //not picking up the element in the combination
        combinationSumHelper(candidates, index+1, target, combination, res);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> combination;
        vector<vector<int>> res;
        combinationSumHelper(nums, 0, target, combination, res);
        return res;
    }
};

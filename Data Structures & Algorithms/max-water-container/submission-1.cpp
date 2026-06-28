class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxWater = 0;
        int l = 0;
        int r = heights.size()-1;
        int currWater = 0;
        while(l < r){
            currWater = min(heights[l], heights[r]) * (r-l);
            maxWater = max(maxWater, currWater);
            if(heights[l] <= heights[r]) l++;
            else r--;
        }
        return maxWater;
    }
};

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;//O(2)

        int count = nums.size()/3;

        int cnt1 = 0;
        int cnt2 = 0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;

        //O(n)
        for(int i = 0; i < nums.size(); i++)
        {
            if(cnt1 == 0 && nums[i] != el2)
            {
                el1 = nums[i]; cnt1++;
            }
            else if(cnt2 == 0 && nums[i] != el1)
            {
                el2 = nums[i]; cnt2++;
            }
            else if(nums[i] == el1) cnt1++;
            else if(nums[i] == el2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            } 
                
        }

        cnt1 = 0; cnt2 = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == el1) cnt1++;
            else if(nums[i] == el2) cnt2++;
        }

        if(cnt1 > count) ans.push_back(el1);
        if(cnt2 > count) ans.push_back(el2);

        return ans;      
        
    }
};

//TC = O(n)
//SC = O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int l = 0;
       int r = 0;

       vector<int> temp;

       while(l < m && r < n)
       {
           if(nums1[l] > nums2[r]) 
           {
                temp.push_back(nums2[r]);
                r++;
           } 
           else
           {
                temp.push_back(nums1[l]);
                l++;
           }
       } 
       if(l < m){
            for(int i = l; i < m; i++)
            {
                temp.push_back(nums1[i]);
            }
       }
       else if( r < n)
       {
            for(int i = r; i < n; i++)
            {
                temp.push_back(nums2[i]);
            }
       }

       for(int j = 0; j < m+n; j++)
       {
            nums1[j] = temp[j];
       }
    }
};
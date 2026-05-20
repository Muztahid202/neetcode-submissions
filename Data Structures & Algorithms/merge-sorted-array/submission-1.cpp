class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int l = 0;
       int r = 0;

       vector<int> temp;

       //O(min(m,n))
       while(l < m && r < n)
       {
           if(nums1[l] > nums2[r]) 
           {
                temp.push_back(nums2[r++]);
           } 
           else
           {
                temp.push_back(nums1[l++]);
           }
       } 
       //O(m)
       while(l < m)
       {
            temp.push_back(nums1[l++]);
            
       }
       //O(n)
       while(r < n)
       {
            temp.push_back(nums2[r++]);
       }

        //O(m+n)
       for(int j = 0; j < m+n; j++)
       {
            nums1[j] = temp[j];
       }
    }
};

//TC = O(m+n)
//SC = O(m+n)
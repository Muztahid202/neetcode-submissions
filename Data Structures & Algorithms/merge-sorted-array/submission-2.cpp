class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = m-1;
        int r = n-1;
        int last = m+n-1;

        while(r >= 0)
        {
            if(l >= 0 && nums1[l] > nums2[r])
            {
                nums1[last--] = nums1[l--];
            }
            else{
                nums1[last--] = nums2[r--];
            }
        }

    }
};

//TC = O(m+n)
//SC = O(m+n)
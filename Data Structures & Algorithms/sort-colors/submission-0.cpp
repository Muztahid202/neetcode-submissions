class Solution {
public:
    void sortColors(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
    }

    void mergeSort(vector<int>&arr, int low, int high)
    {
        if(low >= high) return;

        int mid = (low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }

    void merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;

        int left = low;
        int right = mid + 1;

        while(left <= mid && right <= high)
        {
            if(arr[left] <= arr[right]) 
            {
                temp.push_back(arr[left]);
                left++;
            }
            else 
            {
                temp.push_back(arr[right]);
                right++;
            }
        }

        //copying the extra elements(either of left<=mid or right <= high will be true, both of them can't be true at the same time)
        while(left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        while(right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        //copying elements from the temp
        for(int i = low; i < high + 1; i++)
        {
            arr[i] = temp[i - low];
        }

        
    }
};
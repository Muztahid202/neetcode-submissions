class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);
        int len = 0;
        int l = 0;
        int r = 0;
        int maxLen = 0;
        while( r < s.size()){
            int index = hash[s[r]];
            if(index != -1){
                if(index >= l){
                    l = index+1;
                }
            }
            len = r-l+1;
            maxLen = max(maxLen, len);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};

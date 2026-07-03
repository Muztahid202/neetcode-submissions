class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> appeared;
        int len = 0;
        int l = 0;
        int r = 0;
        int maxLen = 0;
        while( r < s.size()){
            if(appeared.find(s[r]) != appeared.end()){
                auto it = appeared.find(s[r]);
                if(it->second >= l){
                    l = it->second+1;
                }
            }
            len = r-l+1;
            maxLen = max(maxLen, len);
            appeared[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};

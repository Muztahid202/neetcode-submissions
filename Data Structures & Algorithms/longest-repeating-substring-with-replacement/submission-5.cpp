class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int maxFreq = 0;
        int maxLen = 0;
        int hash[26] = {0};
        while (r < s.size()){
            hash[s[r]-'A']++;
            maxFreq = max(maxFreq, hash[s[r]-'A']);
            while((r-l+1)-maxFreq > k){
                hash[s[l]-'A']--;
                l = l + 1;
                maxFreq = 0;
                for(int i = 0; i < 26; i++){
                    maxFreq = max(maxFreq, hash[i]);
                }
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;

    }
};

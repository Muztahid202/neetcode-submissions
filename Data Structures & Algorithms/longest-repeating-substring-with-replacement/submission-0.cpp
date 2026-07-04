class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq = 0;
        int maxLen = 0;
        int hash[26];

        for(int i = 0; i < s.size(); i++){
            for(int k = 0; k < 26; k++) hash[k] = 0;
            for(int j = i; j < s.size(); j++){
                hash[s[j]-'A']++;
                maxFreq = max(maxFreq, hash[s[j]-'A']);
                int substringLen = j - i + 1; 
                int changes = substringLen - maxFreq;
                if(changes <= k){
                    maxLen = max(substringLen, maxLen);
                }
                else break;
            }
        }
        return maxLen;
    }
};

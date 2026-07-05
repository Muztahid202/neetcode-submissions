class Solution {
public:
    string minWindow(string s, string t) {
        int minLen = 10000000;
        int sIndex = -1;
        int l = 0;
        int r = 0;
        int cnt = 0; //how many characters from t I have seen in the substring
        int hash[256] = {0};
        for(int i = 0; i < t.size(); i++){
            hash[t[i]]++;
        }

        while(r < s.size()){
            if(hash[s[r]] > 0){
                cnt++;
            }
            hash[s[r]]--;
            //shrink
            while(cnt == t.size()){
                if(minLen > r-l+1){
                    minLen = r-l+1;
                    sIndex = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        return sIndex == -1 ? "" : s.substr(sIndex, minLen);
    }
};

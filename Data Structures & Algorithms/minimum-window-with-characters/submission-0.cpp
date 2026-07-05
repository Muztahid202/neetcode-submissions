class Solution {
public:
    string minWindow(string s, string t) {
       //holding the counts of the letters
        int countT[58] = {0};
        int countS[58] = {0};
        string ans = "";
        int minLen = 100000000;

        for(char c : t){
            countT[c-'A']++;
        }

        int l = 0;
        int r = 0;

        while(l < s.size() && countT[s[l]-'A'] == 0) l++;
        if(l == s.size()) return ans;
        r = l;
        
        while(r < s.size() && l < s.size()){
            fill(begin(countS), end(countS), 0);
            //cutting out the substring
            string subString = s.substr(l, r-l+1);

            //updating the count of the characters in the substring
            for(char c : subString){
                countS[c-'A']++;
            }

            bool found = true;

            //wiil check if the characters in t is present in the substring or not
            for(int i = 0; i < 58; i++){
                if(countS[i] < countT[i]) found = false; 
            }

            if (found == true){
                if(minLen > subString.size()){
                    ans = subString;
                    minLen = subString.size();
                }
                l++;
                while(l < r && countT[s[l]-'A'] == 0) l++;
            }
            else r++;
            
        }
        return ans; 
    }
};

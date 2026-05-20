class Solution {
public:
    bool isPalindrome(string s) {
        for (char &c : s) {
            c = tolower(c);
        }
        int l = 0;
        int r = s.length()-1;

        while(l < r)
        {
            if(((s[l] >= '0' && s[l] <= '9') || (s[l] >= 'a' && s[l] <= 'z')) && ((s[r] >= '0' && s[r] <= '9') || (s[r] >= 'a' && s[r] <= 'z')))
            {
                if(s[l] != s[r]) return false;
                l++;
                r--;
                continue;
            }
            if(!((s[l] >= '0' && s[l] <= '9') || (s[l] >= 'a' && s[l] <= 'z'))) l++;
            if(!((s[r] >= '0' && s[r] <= '9')  || (s[r] >= 'a' && s[r] <= 'z'))) r--;

        }
        return true;
    }
};

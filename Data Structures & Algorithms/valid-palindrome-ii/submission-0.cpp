class Solution {
public:
    bool validPalindrome(string s) {
        if(isPalindrome(s)) return true;
        else
        {
            for(int i = 0; i < s.length(); i++)
            {
                string newS = s.substr(0,i) + s.substr(i+1);
                if(isPalindrome(newS)) return true;
            }
        }
        return false;
    }

    //check palindrome
    bool isPalindrome(string s)
    {
        int l = 0;
        int r = s.length()-1;

        while(l < r)
        {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
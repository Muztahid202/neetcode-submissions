class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        for(char &c : s){
            c = tolower(static_cast<unsigned char> (c));
        }
        while(start < end){
            if(isalnum(s[start]) && isalnum(s[end])){
                if(s[start] != s[end]) return false;
                start++; end--; 
            }
            else{
                while(!isalnum(s[start])) start++;
                while(!isalnum(s[end])) end--;
            }
        }
        return true;

    }
};

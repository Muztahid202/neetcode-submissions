class Solution {
public:
    bool isPalindrome(string s) {
        string newString = "";
        //O(n)
        for(unsigned char c : s){
            if(isalnum(c)){
                newString += tolower(c);
            }
        }
        //O(n)
        string rNewString = string(newString.rbegin(), newString.rend());
        return newString == rNewString;

    }
};

//Time complexity = O(n)
//Space complexity = O(n)

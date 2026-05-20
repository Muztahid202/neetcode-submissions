class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> counts(26,0);
        //O(n)
        for(char x : s){
            counts[x-'a']++;
        } 
        //O(m)
        for(char y : t){
            counts[y-'a']--;
        }
        //O(26)
        for(int i : counts)
        {
            if(i != 0) return false; 
        }
        return true;
    }
};

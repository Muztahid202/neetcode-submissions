class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        int l = 0;

        string n;

        //O(max(len(word1), len(word2)))
        while(l < word1.size() || l < word2.size())
        {
            if(l < word1.size()) n+= word1[l];
            if(l < word2.size()) n+= word2[l];
            l++;
        }

        return n;
        
    }
};

//TC = O(n+m)
//SC = O(n+m);
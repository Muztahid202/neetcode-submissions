class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        int l = 0;
        int r = 0;

        string n;

        //O(max(len(word1), len(word2)))
        while(l < word1.size() && r < word2.size())
        {
            n += word1[l];
            n += word2[r];
            l++;
            r++;

        }

        if(l < word1.size()){
            for(int j = l; j < word1.size(); j++)
            {
                n += word1[j];
            }
        }

        if(r < word2.size()){
            for(int j = r; j < word2.size(); j++)
            {
                n+= word2[j];
            }
        }

        return n;
        
    }
};

//TC = O(n)
//SC = O(n);
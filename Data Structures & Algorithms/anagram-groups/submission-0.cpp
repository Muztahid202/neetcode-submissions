class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagramList;
        unordered_map<string, vector<string>> groupAnagrams;
        
        for(string s : strs)
        {
            vector<int> count(26,0);
            for(int i = 0; i < s.length(); i++)
            {
                //storing the count for each char that is in the string
                count[s[i] - 'a']++;
            }

            string key = to_string(count[0]);
            for(int i = 1; i < 26; i++)
            {
                key += "," + to_string(count[i]);
            }

            groupAnagrams[key].push_back(s);

        }

        for( auto pair : groupAnagrams)
        {
            anagramList.push_back(pair.second);
        }
        return anagramList;
    }
};

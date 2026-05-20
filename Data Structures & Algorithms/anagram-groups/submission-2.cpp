class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> m;//O(mn)
        //O(m*n*26) = O(mn)
        for(string s : strs)
        {
            vector<int> count(26,0);//O(1)
            for(char c : s)
            {
                count[c - 'a']++;
            }
            string key = "";
            //O(26)
            for(int i : count)
            {
                key += ' ' + to_string(i);
            }
            m[key].push_back(s);
        }
        //O(m)
        for(auto x : m)
        {
            ret.push_back(x.second);
        }
        return ret;

    }
};

class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded;
        for(string s: strs)
        {
            encoded += to_string(s.size()) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;

        int i = 0;
        while(i < s.size())
        {
           int j = 0;
           while(s[j+i] != '#') j++;
           int length = stoi(s.substr(i,j));
           decoded.push_back(s.substr(i+j+1, length));
           i = i+j+length+1;
        }
        return decoded;

    }
};

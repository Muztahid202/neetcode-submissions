class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString;
        for(const string &s : strs){
            encodedString += to_string(s.size()) + "#" + s;
        }
        return encodedString;
    }

    vector<string> decode(string s) {
        vector<string> decodedStrings;
        int i = 0;
        while(i < s.size()){
            int delimPos = s.find('#', i);

            int stringLen = stoi(s.substr(i, delimPos - i));
            i = delimPos + 1;
            string indString = s.substr(i, stringLen);
            decodedStrings.push_back(indString);
            i += stringLen;

        }
        return decodedStrings;

    }
};

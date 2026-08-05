class PrefixTree {
    unordered_set<string> words;
public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
        words.insert(word);
    }
    
    bool search(string word) {
        if(words.count(word)) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        for(const string& word : words){
            string substr = word.substr(0, prefix.size());
            if(substr == prefix) return true;
        }
        return false;
    }
};

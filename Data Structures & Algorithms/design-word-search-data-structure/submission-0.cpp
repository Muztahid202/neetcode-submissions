class Node{
private:
    Node* links[26] = {};
    bool isEnd = false;
public: 
    Node() {}

    void addNode(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* getNode(char ch){
        return links[ch - 'a'];
    }

    bool containsKey(char ch){
        return links[ch - 'a'] != nullptr;
    }

    void setEnd(){
        isEnd = true;
    }

    bool getEnd(){
        return isEnd;
    }

};


class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node *node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                node->addNode(word[i], new Node());
            }
            node = node->getNode(word[i]);
        }
        node->setEnd();
    }
    
    bool searchHelper(string& word, int idx, Node* node){
        if(idx == word.size()) return node->getEnd();

        char ch = word[idx];

        if(ch == '.'){
            for(int i = 0; i < 26; i++){
                char nextCh = i + 'a';
                if(node->containsKey(nextCh)){
                    if(searchHelper(word, idx + 1, node->getNode(nextCh)))
                        return true;
                }
            }
            return false;
        }else{
            if(!node->containsKey(ch)) return false;
            return searchHelper(word, idx+1, node->getNode(ch));
        }
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};


/**
 * TIME COMPLEXITY:
 * 1. addWord(word): O(L)
 *    - Where L is the length of the word being added.
 *    - Each character check and array indexing operation takes O(1) time.
 *
 * 2. search(word):
 *    - Best / Standard Case (No '.' wildcards): O(L)
 *      Traverses a single branch of depth L in the Trie.
 *    - Worst Case (All '.' wildcards, e.g., "..."): O(26^L)
 *      Branching factor of 26 at each character index up to depth L.
 *
 * SPACE COMPLEXITY:
 * 1. addWord(word): O(L) auxiliary space in the worst case to allocate new Trie nodes.
 * 2. search(word): O(L) auxiliary space for the recursion call stack depth.
 * 3. Overall Trie Data Structure: O(N * 26)
 *    - Where N is the total number of characters inserted across all words.
 *    - Each node holds an array of 26 pointers.
 */

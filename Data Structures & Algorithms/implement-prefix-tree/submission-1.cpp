class Node{
private:
    Node* links[26];
    bool isEnd;
public:
    Node(){
        for(int i = 0; i <26; i++){
            links[i] = nullptr;        
        } 
        isEnd = false;
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    bool containsKey(char ch){
        return (links[ch - 'a'] != nullptr);
    }

    Node* getNode(char ch){
        return links[ch - 'a'];
    }

    bool getEnd(){
        return isEnd;
    }

    void setEnd(){
        isEnd = true;
    }
};

class PrefixTree {
    Node* root;
public:
    PrefixTree() {
        root = new Node(); 
    }
    
    void insert(string word) {
        Node* node = root;

        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }

            node = node->getNode(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;

        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])) return false;
            node = node->getNode(word[i]);
        }
        return node->getEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;

        for(int i = 0; i < prefix.size(); i++){
            if(!node->containsKey(prefix[i])) return false;
            node = node->getNode(prefix[i]);
        }
        return true;
    }
};

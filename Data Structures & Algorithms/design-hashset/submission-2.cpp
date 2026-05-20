class Node {
    public:
        int key;
        Node* next;

        Node(int val)
        {
            key = val;
            next = nullptr;
        }
};


class MyHashSet {
private: 
    vector<Node*> buckets;

    int hash(int key)
    {
        return key % 10000;
    } 
public:
    MyHashSet() { 
        buckets.resize(10000, nullptr);
    }
    
    void add(int key) {
        int index = hash(key);

        Node* curr = buckets[index];
        Node* newNode = new Node(key);

        if(curr == nullptr){
            buckets[index] = newNode;
            return;
        }  

        Node* prev = nullptr;

        while (curr != nullptr){
            if(curr->key == key) return;
            prev = curr;
            curr = curr->next;
        }
        curr = newNode;
        prev->next = curr;
        return;
    }
    
    void remove(int key) {
        int index = hash(key);
        Node* curr = buckets[index];

        if(curr == nullptr){
            return;
        }  

        Node* prev = nullptr;

        while (curr != nullptr){
            if(curr->key == key)
            {
                if(prev)
                    prev->next = curr->next;
                else buckets[index] = curr->next;
                delete curr;
                return;
            } 
            prev = curr;
            curr = curr->next;
        }
        return;
    }
    
    bool contains(int key) {
        int index = hash(key);

        Node* curr = buckets[index];

        if(curr == nullptr){
            return false;
        }  

        while (curr != nullptr){
            if(curr->key == key) return true;
            curr = curr->next;
        }
         return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
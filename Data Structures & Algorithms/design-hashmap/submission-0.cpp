class Node{
public:
    int key;
    int value;
    Node* next;

    Node(int x, int y)
    {
        key = x;
        value = y;
        next = nullptr;
    }

};

class MyHashMap {
private:
    vector<Node*> a;

    int hash(int key)
    {
        return key % 10000;
    }

public:
    MyHashMap() {
        a.resize(10000, nullptr);
    }
    
    void put(int key, int value) {
        int index = hash(key);
        Node* curr = a[index];
        Node* newNode = new Node(key, value);
        Node* prev = nullptr;

        if(curr == nullptr)
        {
            a[index] = newNode;
            return;
        }

        while(curr != nullptr)
        {
            if(curr->key == key) 
            {
                curr->value = value;
                return;
            }

            prev = curr;
            curr = curr->next;
        }
        curr = newNode;
        prev->next = curr;

    }
    
    int get(int key) {
        int index = hash(key);
        Node* curr = a[index];

        if(curr == nullptr)
        {
            return -1;
        }

        while(curr != nullptr)
        {
            if(curr->key == key) 
            {
                return curr->value;
            }
            curr = curr->next;
        }
        return -1;
        
    }
    
    void remove(int key) {
        int index = hash(key);
        Node* curr = a[index];
        Node* prev = nullptr;

        if(curr == nullptr)
        {
            return;
        }

        while(curr != nullptr)
        {
            if(curr->key == key) 
            {
                if(prev)
                {
                    prev->next = curr->next;
                }
                else a[index] = nullptr; 
                delete curr;
                return;
            }

            prev = curr;
            curr = curr->next;
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
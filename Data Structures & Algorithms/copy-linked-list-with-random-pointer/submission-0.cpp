/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        unordered_map<Node*, Node*> copyMap;
        Node* temp = head;
        //creating the dummy nodes and storing <original, copy> map
        while(temp != NULL){
            Node *newNode = new Node(temp->val);
            copyMap.emplace(temp,newNode);
            temp = temp->next;
        }

        //now setting up the next and random pointer
        temp = head;
        Node* copyNode = NULL;
        while(temp != NULL){
            copyNode = copyMap[temp];
            copyNode->next = temp->next == NULL ? NULL : copyMap[temp->next];
            copyNode->random = temp->random == NULL ? NULL : copyMap[temp->random];
            temp = temp->next;
        }

        return copyMap[head];
    }
};

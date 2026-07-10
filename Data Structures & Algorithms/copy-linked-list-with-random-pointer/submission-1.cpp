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
        Node* temp = head;

        //creating the new copied nodes in place in the original list
        while(temp != NULL){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }

        //assigning the random pointers for the copied nodes
        temp = head;
        while(temp != NULL){
            temp->next->random = temp->random == NULL ? NULL : temp->random->next;
            temp = temp->next->next;
        }

        //assigning the next pointers and fixing up the original list
        Node* dNode = new Node(-1);
        Node* res = dNode;
        temp = head;

        while(temp != NULL){
            res->next = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            res = res->next;
        }
        res->next = NULL;
        return dNode->next;
    }
};

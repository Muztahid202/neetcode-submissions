/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        unordered_map<int, pair<ListNode*, ListNode*>> map;//map for storing index key and the value is the node and it's previous node

        ListNode* temp = head;
        ListNode* prev = nullptr;
        int index = 1;
        //filling up the map
        while(temp!= nullptr){
            map[index] = {temp, prev};
            index++; 
            prev = temp;
            temp = temp->next;
        }
        //finding out the node to be deleted
        auto it = map.find(index-n);
        ListNode* deleteNode = it->second.first;
        prev = it->second.second;
        if(prev != nullptr) prev->next = deleteNode->next;
        else{
            head = head->next;
        }
        delete(deleteNode);
        return head;
    }
};

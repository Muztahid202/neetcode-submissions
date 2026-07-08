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
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> nodeSet;
        ListNode* temp = head;

        while(temp != nullptr){
            if(nodeSet.find(temp) != nodeSet.end()){
                return true;
            }
            nodeSet.insert(temp);
            temp = temp->next;
        }
        return false;
    }
};

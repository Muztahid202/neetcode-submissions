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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* head = nullptr;
        ListNode* temp3 = nullptr;

        while(temp1 != nullptr && temp2 != nullptr){
            if(head == nullptr){
                if(temp1->val < temp2->val){
                    ListNode* newNode = new ListNode(temp1->val);
                    head = newNode;
                    temp1 = temp1->next;
                }else{
                    ListNode* newNode = new ListNode(temp2->val);
                    head = newNode;
                    temp2 = temp2->next;
                }
                temp3 = head;
                continue;
            }else if(temp1->val < temp2->val){
                ListNode* newNode = new ListNode(temp1->val);
                temp3->next = newNode;
                temp1 = temp1->next;
            }else{
                ListNode* newNode = new ListNode(temp2->val);
                temp3->next = newNode;
                temp2 = temp2->next;
            }
            temp3 = temp3->next;
        }
        if(temp3 == nullptr) return temp1 != nullptr ? temp1 : temp2;
        if(temp1 != nullptr) temp3->next = temp1;
        if(temp2 != nullptr) temp3->next = temp2;
        return head;
    }
};

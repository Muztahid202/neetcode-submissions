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
    void reorderList(ListNode* head) {
        if(head -> next == nullptr) return;
        if(head->next->next == nullptr) return;
        ListNode* slow = head;
        ListNode* fast = head->next;
        //detecting the 2nd half
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* secondHalf = slow->next;
        slow->next = nullptr; //first halfs last node pointing to null
        //so now 2 separate lists

        //reversing the 2nd half
        ListNode* temp = secondHalf;
        ListNode* prev = nullptr;
        ListNode* front;
        while(temp != nullptr){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        //merge the 2 halves
        ListNode* left = head;
        ListNode* right = prev;

        while(left != nullptr && right != nullptr){
            front = left->next;
            prev = right->next;
            left->next = right;
            right->next = front;
            left = front;
            right = prev;
        }
        return;
    }
};

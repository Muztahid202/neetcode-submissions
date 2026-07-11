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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nodes;
        for(ListNode* head : lists){
            ListNode* temp = head;
            while(temp != nullptr){
                nodes.push_back(temp->val);
                temp = temp->next;
            }
        }
        //sorting the array
        sort(nodes.begin(), nodes.end());
        ListNode* dNode = new ListNode(-100000000);
        ListNode* prev = dNode;

        //creating the nodes for the sorted array
        for(int num : nodes){
            ListNode* node = new ListNode(num);
            prev->next = node;
            prev = node;
        }
        prev->next = nullptr;
        return dNode->next;
        
    }
};

//TC = O(N) + O(NlogN) + O(N)
//SC = O(N) + O(N)

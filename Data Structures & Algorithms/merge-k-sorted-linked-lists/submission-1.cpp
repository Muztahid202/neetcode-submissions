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
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        ListNode* dNode = new ListNode(-10000000);
        ListNode* temp = dNode;
        
        //storing all the heads in a priority queue
        for(ListNode* head : lists){
            if(head != nullptr)
                pq.push({head->val, head});
        }
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            temp->next = it.second;
            if(it.second->next != nullptr) 
                pq.push({it.second->next->val, it.second->next});
            temp = temp->next;
        }

        temp->next = nullptr;
        return dNode->next;

    }
};

//TC = O(klogK) + O(KN. 3logK)
//SC = O(k);


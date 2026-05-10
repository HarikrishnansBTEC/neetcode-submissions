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
    ListNode* reverseList(ListNode* head) {

            if(head == nullptr) return nullptr;
            ListNode* prev = head;
            ListNode* curr = head->next;
            while(curr!= nullptr)
            {
                ListNode* next_cu = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next_cu;
            }
            head->next = nullptr;
            head = prev;
            return head;
        
    }
};

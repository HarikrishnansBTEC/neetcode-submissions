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
        if(!head || !head->next) return nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = curr->next;

        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode* temp = prev;
        curr = prev;
        while(n!=0)
        {
            n--;
            if(n==0)
            {
                if(curr == prev)
                {
                    curr = curr->next;
                    prev->next = nullptr;
                }
                else
                {
                    prev->next = curr->next;
                    curr->next = nullptr;
                    curr = temp;
                }
            }
            prev = curr;
            curr = curr->next;
        }
        // return temp;
        ListNode* curr1 = prev;
        ListNode* prev1 = nullptr;
        ListNode* next1 = prev->next;

        while(curr1)
        {
            next1 = curr1->next;
            curr1->next = prev1;
            prev1 = curr1;
            curr1 = next1;
        }

        return prev1;
    }
};

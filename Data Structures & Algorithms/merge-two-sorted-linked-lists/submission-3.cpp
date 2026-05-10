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

        if(temp1==nullptr && temp2==nullptr) return nullptr;
        else if(temp1 ==nullptr && temp2 != nullptr) return temp2;
        else if(temp1 !=nullptr && temp2 == nullptr) return temp1;
        
        ListNode* next1 = list1->next;
        ListNode* next2 = list2->next;


        while(temp1 !=nullptr && temp2 != nullptr)
        {
            if(temp1 != nullptr && temp1->val <= temp2->val)
            {
                while(temp1->next != nullptr && temp1->next->val <= temp2->val)
                {
                    temp1 = temp1->next;
                }
                next1 = temp1->next;
                temp1->next = temp2;
                temp1 = next1;
              
            }
            else if(temp2 != nullptr)
            {
                while(temp2->next != nullptr && temp2->next->val <= temp1->val)
                {
                    temp2 = temp2->next;
                }
                next2 = temp2->next;
                temp2->next = temp1;
                temp2 = next2;
            }
        }
        if(list1->val<= list2->val) return list1;
        else return list2;
    }
};

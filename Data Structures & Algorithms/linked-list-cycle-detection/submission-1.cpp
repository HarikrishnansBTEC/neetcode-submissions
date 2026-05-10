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

        if(!head) return false;
        
        unordered_set<ListNode *> hash;
        ListNode * temp = head;

        while(temp->next != nullptr)
        {
            if(hash.contains(temp))
            {
                return true;
            }
            hash.insert(temp);
            temp = temp->next;
        }
        return false;

    }
};

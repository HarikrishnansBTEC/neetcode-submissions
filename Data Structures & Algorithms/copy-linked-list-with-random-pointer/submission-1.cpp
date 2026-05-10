/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        unordered_map<Node*,Node*> hash;
        Node* temp = head;
        while(temp != nullptr)
        {
            Node* nn = new Node(temp->val);
            hash[temp] = nn;
            temp = temp->next;
        }
        temp = head;
        while(temp != nullptr)
        {
            hash[temp]->next = hash[temp->next];
            hash[temp]->random = hash[temp->random];
            temp = temp->next;
        }
        return hash[head];
        
    }
};

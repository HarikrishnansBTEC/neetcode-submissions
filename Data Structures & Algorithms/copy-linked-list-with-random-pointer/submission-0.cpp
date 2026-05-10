class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        unordered_map<Node*, Node*> oldToNew;
        
        // Pass 1: Create all nodes
        Node* curr = head;
        while (curr) {
            oldToNew[curr] = new Node(curr->val);
            curr = curr->next;
        }
        
        // Pass 2: Connect next and random
        curr = head;
        while (curr) {
            oldToNew[curr]->next = oldToNew[curr->next];
            oldToNew[curr]->random = oldToNew[curr->random];
            curr = curr->next;
        }
        
        return oldToNew[head];
    }
};
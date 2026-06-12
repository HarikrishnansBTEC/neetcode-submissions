class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return nullptr;

        // Map child pointer to parent pointer
        unordered_map<TreeNode*, TreeNode*> parentMap;
        queue<TreeNode*> nodes;

        // Fill parent map using BFS
        bfs(root, nodes, parentMap);

        // Store all ancestors of node p
        unordered_set<TreeNode*> ancestors;
        while (p != nullptr) {
            ancestors.insert(p);
            p = parentMap[p]; 
        }

        // Find the first matching ancestor for node q
        while (q != nullptr) {
            if (ancestors.count(q)) {
                return q;
            }
            q = parentMap[q];
        }

        return nullptr;
    }

    void bfs(TreeNode* root, queue<TreeNode*>& nodes, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        nodes.push(root);
        parentMap[root] = nullptr; 

        while (!nodes.empty()) {
            TreeNode* curr = nodes.front();
            nodes.pop();

            if (curr->left) {
                parentMap[curr->left] = curr; 
                nodes.push(curr->left);
            }
            if (curr->right) {
                parentMap[curr->right] = curr; 
                nodes.push(curr->right);
            }
        }
    }
};

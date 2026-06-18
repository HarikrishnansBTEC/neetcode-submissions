class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }

private:
    bool validate(TreeNode* node, long long min_val, long long max_val) {
        // An empty tree is a valid BST
        if (!node) return true;

        // If the current node's value violates the min/max constraints
        if (node->val <= min_val || node->val >= max_val) return false;

        // Check left subtree (update max) and right subtree (update min)
        return validate(node->left, min_val, node->val) && 
               validate(node->right, node->val, max_val);
    }
};
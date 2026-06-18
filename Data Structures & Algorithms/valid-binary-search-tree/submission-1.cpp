class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long long prev = LONG_MIN;
        return inOrder(root, prev);
    }

private:
    bool inOrder(TreeNode* node, long long& prev) {
        if (!node) return true;

        // 1. Check Left Subtree
        if (!inOrder(node->left, prev)) return false;

        // 2. Check Current Node
        if (node->val <= prev) return false;
        prev = node->val; // Update previous value to current

        // 3. Check Right Subtree
        return inOrder(node->right, prev);
    }
};
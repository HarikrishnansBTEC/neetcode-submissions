class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        calculateHeightAndDiameter(root, maxDiameter);
        return maxDiameter;
    }

private:
    int calculateHeightAndDiameter(TreeNode* node, int& maxDiameter) {
        if (node == nullptr) {
            return 0; // Height of an empty node is 0
        }

        // Recursively find the height of left and right subtrees
        int leftHeight = calculateHeightAndDiameter(node->left, maxDiameter);
        int rightHeight = calculateHeightAndDiameter(node->right, maxDiameter);

        // The diameter passing through the current node is the sum of left and right heights
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        // Return the height of the current subtree to the parent call
        return max(leftHeight, rightHeight) + 1;
    }
};
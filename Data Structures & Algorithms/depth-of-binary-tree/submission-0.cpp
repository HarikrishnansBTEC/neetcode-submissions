/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {

        if(root == nullptr) return 0;
        int sum_left = 1;
        int sum_right = 1;
        sum_left += maxDepth(root->left);
        sum_right += maxDepth(root->right);
        int sum = max(sum_left,sum_right);
        
        return sum;
        
    }
};

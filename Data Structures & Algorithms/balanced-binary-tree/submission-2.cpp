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
    bool isBalanced(TreeNode* root) {
        
        if(root==nullptr) return true;
        bool temp = true;
        int left = findheight(root->left,temp);
        int right = findheight(root->right,temp);
        cout<<left<<" "<<right;

        if(abs(left - right) > 1 || !temp) return false;
        return true;

                
    }

    int findheight(TreeNode* root,bool &temp)
    {
        if(root == nullptr) return 0;
        
        int left = findheight(root->left,temp);
        int right = findheight(root->right,temp);

        if(abs(left - right)>1)
        {
            temp = false;
        }

        return max(left,right) + 1;

    }
};

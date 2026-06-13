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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int sum=0;
        dfs(root,sum,root->val);
        return sum;
    }

    void dfs(TreeNode* root, int& sum, int check)
    {
        if(!root) return;

        if(root->val>= check)
        {
            cout<<root->val<<" "<<endl;
            sum++;
            
        }
        dfs(root->left,sum,max(root->val,check));
        dfs(root->right,sum,max(root->val,check));


    }
};

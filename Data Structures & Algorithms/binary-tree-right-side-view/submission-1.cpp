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
    vector<int> rightSideView(TreeNode* root) {

        
        vector<int> result;
        if(!root) return result;
        queue<TreeNode*> level;
        level.push(root);

        while(!level.empty())
        {
            int size = level.size();
            // TreeNode* curr = level.front();
            // level.pop();
            int last;
            for(int i=0;i<size;i++)
            {
                TreeNode* curr = level.front();
                level.pop();
                if(i==size-1)
                {
                    last = curr->val;
                }
                if(curr->left)
                {
                    level.push(curr->left);
                    
                }
                if(curr->right)
                {
                    level.push(curr->right);
                }
            }
            result.push_back(last);
        }
        return result;

    }
};

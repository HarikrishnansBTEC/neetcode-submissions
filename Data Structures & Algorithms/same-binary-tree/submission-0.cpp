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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool temp = true;
        findSame(p,q,temp);
        return temp;
    }

    void findSame(TreeNode* p,TreeNode* q,bool& temp)
    {
        if((!p&&q) || (p&&!q))
        {
            temp = false;
        }
        if(p == nullptr || q == nullptr)return ;


        findSame(p->left,q->left,temp);
        // findSame(q->left);
        if(p->val != q->val)
        {
            temp = false;
        }
        findSame(p->right,q->right,temp);
        
        if(p->val != q->val)
        {
            temp = false;
        }


    }
};

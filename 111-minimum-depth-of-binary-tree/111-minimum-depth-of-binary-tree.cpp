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
    int d;
    
    void traverse(TreeNode* t, int l)
    {
        if(t->left == nullptr && t->right==nullptr)
        {
            d = min(d,l);
            return;
        }
        if(l>=d) return;
        if(t->right) traverse(t->right,l+1);
        if(l>=d) return;
        if(t->left) traverse(t->left,l+1);
    }
    
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        d=INT_MAX;
        traverse(root,1);
        return d;
    }
};
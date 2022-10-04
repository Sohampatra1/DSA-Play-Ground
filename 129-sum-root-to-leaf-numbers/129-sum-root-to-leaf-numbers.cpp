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
    int ans=0;
    void dfs(TreeNode* cu,string cusum)
    {
        if(cu->left==NULL && cu->right==NULL)
        {
            cusum+=char(cu->val+'0');
            ans+=stoi(cusum);
            //cout<<cusum<<" ";
            return;
        }
        if(cu->left==NULL)
        {
            dfs(cu->right,cusum+char(cu->val+'0'));
        }
        else
        {
            if(cu->right==NULL)
            {
                dfs(cu->left,cusum+char(cu->val+'0'));
            }
            else
            {
                dfs(cu->right,cusum+char(cu->val+'0'));
                dfs(cu->left,cusum+char(cu->val+'0'));
            }
        }
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        string cusum="";
        dfs(root,cusum);
        return ans;
    }
};
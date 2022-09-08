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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrder(root,0,ans);
        return ans;
    }
    
    void levelOrder(TreeNode* root, int level, vector<vector<int>> &ans){
        if(!root) return;
        if(ans.size()>level){
            ans[ans.size()-level-1].push_back(root->val);
        } else{
            vector<int> temp(1,root->val);
            ans.insert(ans.begin(),temp);
        }
        levelOrder(root->left,level+1,ans);
        levelOrder(root->right,level+1,ans);
        
    }
};
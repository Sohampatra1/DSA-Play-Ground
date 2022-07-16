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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> ret;
    vector<int> path;
    pathSum(root, targetSum, path, ret);
    return ret;
  }


  void pathSum(TreeNode* root, int targetSum, vector<int> & path, vector<vector<int>> & ret) {
    if (!root)
      return;
    path.push_back(root->val);
    pathSum(root->left, targetSum-root->val, path, ret);
    pathSum(root->right, targetSum-root->val, path, ret);
    if (!root->left && !root->right && targetSum == root->val)
      ret.push_back(path);
    path.pop_back();
  }
        
        
        
        
    
};
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
    string solve(TreeNode* root, vector<TreeNode*>& res, unordered_map<string, int>& mp){
        if(!root) return "" ;
           string temp=to_string(root->val)+","+solve(root->left,res,mp)+","+solve(root->right,res,mp);
           if(mp[temp]==1) res.push_back(root);
        mp[temp]++;
        return temp;
        }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
         unordered_map<string,int> mp;
             vector<TreeNode*> res;
          solve(root,res,mp);
         return res;
    }
};
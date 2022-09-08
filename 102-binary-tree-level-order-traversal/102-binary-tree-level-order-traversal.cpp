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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() != 0){
            int len = q.size();
            vector<int> res;
            for(int i=0; i<len; i++) {
                TreeNode* valNode = q.front();
                q.pop();
                res.push_back(valNode->val);
                if(valNode->left != NULL){
                    q.push(valNode->left);
                }
                if(valNode->right != NULL){
                    q.push(valNode->right);
                }
            }
            result.push_back(res);
        }
        return result; 
    }
};
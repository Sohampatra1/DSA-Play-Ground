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
    int longestZigZag(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        int ans = 0;
        while(!todo.empty()){
            int num = todo.size();
            while(--num>=0){
                auto node = todo.front();
                todo.pop();
                if(node.first->left!=nullptr){
                    ans = max(ans, node.second.second+1);
                    todo.push({node.first->left, {node.second.second+1, 0}});
                }
                if(node.first->right!=nullptr){
                    ans = max(ans, node.second.first+1);
                    todo.push({node.first->right, {0, node.second.first+1}});
                }
            }
        }
        return ans;
    }
};
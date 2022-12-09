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

    void dfs(TreeNode *root, int minE, int maxE, int &ans)
    {
        if(root == NULL) return;
        minE = min(root->val, minE);
          maxE = max(root->val, maxE);
           ans = max(ans, abs(minE - maxE));

dfs(root->left, minE, maxE, ans);
        dfs(root->right, minE, maxE, ans);
                                  }
  int maxAncestorDiff(TreeNode* root) {
         if(root == NULL or root->left == NULL and root->right == NULL) return 0;
            int ans = 0;
               int minE = root->val, maxE = root->val;
                  dfs(root, minE, maxE, ans);
        return ans;
    }
};
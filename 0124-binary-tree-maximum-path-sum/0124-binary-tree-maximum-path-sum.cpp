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
    int maxSumCurve = INT_MIN;
    
    int helper(TreeNode* root) {
        
        if (root == NULL) return 0;
        int leftSum = helper(root->left), rightSum = helper(root->right);
        int temp = root->val;
        if (temp + leftSum > temp) temp += leftSum;
        if (temp + rightSum > temp) temp += rightSum;
        maxSumCurve = max(temp, maxSumCurve);
        temp = max(leftSum, rightSum);
        return root->val + (temp >= 0 ? temp : 0);
        
    }
    
    int maxPathSum(TreeNode* root) {
        
        return max(maxSumCurve, helper(root));
        
    }
};
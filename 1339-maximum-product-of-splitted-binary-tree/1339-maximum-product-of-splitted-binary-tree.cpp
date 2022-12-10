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
    long long M=1e9+7;
    int sum=0;
      int getSum(TreeNode* root){
        if(!root)return 0;
         sum+=root->val;
        getSum(root->left);
          getSum(root->right);
        return sum;
    }
    int solve(TreeNode* root,int& totalSum,long long& product){
        if(!root)return 0;
         int left=solve(root->left,totalSum,product);
          int right=solve(root->right,totalSum,product);
        int sum=left+right+root->val;
        long long totalProduct=(long)sum*(totalSum-sum);
        product=max(product,totalProduct);
        return sum;
    }
    int maxProduct(TreeNode* root) {
        int totalSum=getSum(root);
          long long product=0;
        solve(root,totalSum,product);
         return product%M;
    }
};
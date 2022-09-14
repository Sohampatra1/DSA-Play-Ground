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
    int result=0;
    void palindrome(TreeNode* root, int n,vector<int> node){
        if(node[root->val]%2==0)
            n++;
        else
            n--;
        node[root->val]++;
        
        if(root->left==NULL && root->right==NULL){
            if(n<=1)
                result++;
            return;
        }
       
        if(root->left && root->right){
            palindrome(root->right,n,node);
            palindrome(root->left,n,node);
        }
        else if(root->left)
            palindrome(root->left,n,node);
        else if(root->right)
            palindrome(root->right,n,node);
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> a = {0,0,0,0,0,0,0,0,0,0};
        palindrome(root,0,a);
        return result;
    }
};
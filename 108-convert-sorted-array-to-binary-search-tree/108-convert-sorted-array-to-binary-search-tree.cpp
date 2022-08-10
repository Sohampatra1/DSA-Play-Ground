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
TreeNode* buildTree(vector<int> &nums, int l, int r)
    {
        TreeNode* root = NULL;
        if(r<l) return root;
        if(r==l) {
            root = new TreeNode(nums[l]);
            return root;
        }
        int mid = (l+r)/2;
        root = new TreeNode(nums[mid]);
        root->left = buildTree(nums, l, mid-1);
        root->right = buildTree(nums, mid+1, r);
        return root;

    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = NULL;
        if(nums.size()==1){
            root = new TreeNode(nums[0]);
            return root;
        }
        root = buildTree(nums, 0, nums.size()-1);
        return root;
    }
};
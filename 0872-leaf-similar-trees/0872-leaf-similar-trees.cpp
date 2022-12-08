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
    void inorder(TreeNode* root, vector<int>&vec){
        if(root == NULL)
            return;

        inorder(root->left, vec);
        if((root->left == NULL) && (root->right == NULL))
        {
            vec.push_back(root->val);
        }
        inorder(root->right, vec);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>vec1;
        vector<int>vec2;
        inorder(root1, vec1);
        inorder(root2, vec2);

        int n1 = vec1.size();
        int n2 = vec2.size();
        if(n1 == n2){
            for(int i=0; i<n1; i++){
                if(vec1[i] != vec2[i]){
                    return false;
                }
            }
        } else{
            return false;
        }
        return true;
    }
};
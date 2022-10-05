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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1 ){
            TreeNode * h = new TreeNode(val);
            h->left = root;
            return h;
        }
        queue<TreeNode *> pq;
        pq.push(root);
        int s = 2 ;
        while(s!=depth){
            int dd = pq.size();
            for(int i = 0 ; i < dd ; i++){
                TreeNode * f = pq.front();
                pq.pop();
                if(f->left != NULL){
                    pq.push(f->left);
                }
                if(f->right != NULL){
                    pq.push(f->right);
                }
            }
            s++;
        }
        int c = pq.size();
        for(int i = 0 ; i < c ; i++){
            TreeNode* left1 = new TreeNode(val);
            TreeNode* right1 = new TreeNode(val);
            TreeNode * fr = pq.front();
            pq.pop();
            if(fr->left == NULL){
                fr->left = left1;
            }
            else{
                TreeNode * x = fr->left;
                fr->left = left1;
                left1->left = x;
            }
            if(fr->right == NULL){
                fr->right = right1;
            }
            else{
                TreeNode * x = fr->right;
                fr->right = right1;
                right1->right = x;
            }
        }
        return root;
    }
};
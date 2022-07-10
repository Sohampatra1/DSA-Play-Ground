class Solution {
public:
    int maxDepth(TreeNode* root){
        if(!root){
            return 0;
        }
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
    void zzO(TreeNode* root,int c,vector<int>& sres,int i){
        if(!root){return;}
        if(c==i){
            sres.push_back(root->val);
            return;
        }
        else if(i%2==1){
            zzO(root->left,c+1,sres,i);
            zzO(root->right,c+1,sres,i);
        }
        else{
            zzO(root->right,c+1,sres,i);
            zzO(root->left,c+1,sres,i);
        }
    }                 
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int n=maxDepth(root);
        vector<vector<int>> res;
        for(int i=1;i<=n;i++){
            vector<int> sres;
            zzO(root,1,sres,i);
            res.push_back(sres);
        }
        return res;
    }
};
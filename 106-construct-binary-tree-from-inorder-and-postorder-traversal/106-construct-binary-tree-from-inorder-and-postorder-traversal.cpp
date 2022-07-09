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
    TreeNode*helper(vector<int>&in,vector<int>&post,int IN_SI,int IN_EI,int POST_SI,int POST_EI){
    if(IN_SI > IN_EI){
        return NULL;
    }
    int rootdata = post[POST_EI];
    int rootindex = -1;
     for(int i = IN_SI; i<=IN_EI; i++){
         if(in[i] == rootdata){
             rootindex = i;
             break;
         }
     }
     
            int Left_ins = IN_SI;
            int Left_ine = rootindex-1;
            int Left_posts = POST_SI;
            int Left_poste = Left_ine - Left_ins + Left_posts;
            int Right_ins = rootindex+1;
            int Right_ine = IN_EI;
            int Right_posts = Left_poste + 1;
            int Right_poste  = POST_EI - 1;  
        
    TreeNode*root = new TreeNode(rootdata);
    root->left = helper(in,post,Left_ins,Left_ine,Left_posts,Left_poste);
    root->right = helper(in,post,Right_ins,Right_ine,Right_posts,Right_poste);
    return root;
            
        }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        return helper(inorder,postorder,0,size-1,0,size-1);
    
    }
};
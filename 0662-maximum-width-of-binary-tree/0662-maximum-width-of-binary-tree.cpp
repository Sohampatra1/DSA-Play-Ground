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
       int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode*,int>>q;
           q.push({root,0});
          long ans=0;
         while(!q.empty())
          {
            int sz=q.size();
              long start=q.front().second;
             long end=q.back().second;
              ans=max(ans,end-start+1);
            while(sz--)
            {
                auto temp=q.front();
                q.pop();
                 long idx=temp.second;
                   TreeNode* node=temp.first;
                if(node->left)
                 q.push({node->left,2*idx+1});
                    if(node->right)
                    q.push({node->right,2*idx+2});    
              } 
        }
                return ans;    
      }
};

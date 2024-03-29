class Solution {
    void helper(TreeNode *root,int row,int col,map<int,vector<pair<int,int>>>&mp)
    {
        if(root==NULL)return;
         mp[col].push_back(make_pair(row, root->val));
        
        if(root->left)helper(root->left,row+1,col-1,mp);
        if(root->right)helper(root->right,row+1,col+1,mp);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
     map<int,vector<pair<int,int>>>mp;
         vector<vector<int>>ans;
       
        if(root->left ==NULL && root->right==NULL){
            ans.push_back({root->val});
            return ans;
        }
        int row=0,col=0;
      
       helper(root,0,0,mp);
          

    
       for(auto it:mp){
            sort(it.second.begin(), it.second.end());
            vector<int> tmp;
            for(auto i:it.second)tmp.push_back(i.second);
            ans.push_back(tmp);
        }
        return ans;
    }
};
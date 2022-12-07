class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL)
            return 0;
        queue <TreeNode *> q;
        int sum=0;
        q.push(root);
        // cout<<q.front()->val;
        while(!q.empty()){
            TreeNode * temp=q.front();
            q.pop();
            if(temp->val>=low && temp->val<=high)
                sum+=temp->val;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        return sum;
    }
};

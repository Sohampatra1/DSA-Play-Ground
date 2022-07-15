/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
            return "#,";
        return to_string(root->val) + ',' + serialize(root->left) + serialize(root->right) ;
    }

    // Decodes your encoded data to tree.
    int ind=0;
    TreeNode* deserialize(string& data) {
        if(ind==data.length())
            return NULL;
        
        string t;
        while(ind<data.length() && data[ind]!=',')
        {
            t+=data[ind++];
        }
        ind++;
        if(t=="#")
            return NULL;
        int val=stoi(t);
        TreeNode* root= new TreeNode(val);
        root->left=deserialize(data);
        root->right=deserialize(data);
        return root;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
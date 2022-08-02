/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* populate(Node *root1)
    {
        if(root1==NULL)
            return NULL;
        else if(root1->left)
        {
            return root1->left;
        }
        else if(root1->right)
            return root1->right;
        return populate(root1->next);
    }
    void fin(Node *root)
    {
        if(root==NULL)
            return;
       if(root->left && root->right)
         {
             root->left->next=root->right;
           root->right->next=populate(root->next); 
         }
        else if(root->right)
        {
            root->right->next=populate(root->next);
        }
        else if(root->left)
            root->left->next=populate(root->next);
  
         fin(root->right);  
         fin(root->left);
       
    }
    Node* connect(Node* root) {
        fin(root);
        return root;
    }
};
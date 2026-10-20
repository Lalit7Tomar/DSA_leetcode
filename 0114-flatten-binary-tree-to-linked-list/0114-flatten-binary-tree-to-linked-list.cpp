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
   // preorder traversal
   
    void flatten(TreeNode* root) {
                 if(root==nullptr) return;
                  TreeNode* a=root->left;
         TreeNode* b=root->right;
          root->left=nullptr;
        
         flatten(a);
         flatten(b);
           root->right=a;
           TreeNode* curr=root;
           
           while(curr->right!=nullptr){
            curr=curr->right;
           }
           curr->right=b;
             }
};
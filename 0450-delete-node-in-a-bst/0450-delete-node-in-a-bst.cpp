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
 /*

            7
          5
        4        
          6
 */
class Solution {
public:

    void delet(TreeNode* root,TreeNode* parent,int key){
      if(root==nullptr) return;
      if(root->val==key) {
        
         if(parent->val<key){
            TreeNode* a=root->left;
            TreeNode* b=root->right;
           if(a){
                        parent->right=a;

            while(a->right!=nullptr){
                a=a->right;
            }
            a->right=b;
           }
           else{
             parent->right=b;
             
           }
        }
         else{
             TreeNode* a=root->left;
            TreeNode* b=root->right;
           if(a){
                        parent->left=a;

            while(a->right!=nullptr){
                a=a->right;
            }
            a->right=b;
           }
           else{
             parent->left=b;
             
           }
         }
      }
     else if(root->val>key){
        delet(root->left,root,key);
      } 
      else if(root->val<key){
        delet(root->right,root,key);
      } 
      return;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root && root->val==key){
            TreeNode* a=root->left;
            TreeNode* b=root->right;
            if(a){
                TreeNode* temp=a;
                while(temp->right!=nullptr){
                    temp=temp->right;
                }
                temp->right=b;
                return a;
            }
            else{
                return b;
            }
        }
      delet(root,root,key);
       return root;
    }
};
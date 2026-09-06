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
     void traversal(TreeNode* parent,int data){
        if(parent->val>data){
           if(parent->left==nullptr){
            parent->left=new TreeNode(data);
           }
           
            
            else{
                traversal(parent->left,data);
            }
        }
        if(parent->val<data){
           if(parent->right==nullptr){
            parent->right=new TreeNode(data);
           }
           
            
            else{
                traversal(parent->right,data);
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr) return new TreeNode(val);
         traversal(root,val);
         return root;
    }
};
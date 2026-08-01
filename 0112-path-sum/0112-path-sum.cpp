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
     bool helper(TreeNode* root,int targetSum,int currvalue){
        if(currvalue==targetSum &&(root->left==NULL && root->right==NULL)){
            return true;
        }
        bool leftresult=false;
        if(root->left){
           leftresult= helper(root->left,targetSum,currvalue+root->left->val);
        }
        bool rightresult=false;
        if(root->right){
           rightresult= helper(root->right,targetSum,currvalue+root->right->val);
        }
        return leftresult || rightresult;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
      if(root==NULL) return false;
       bool result=helper(root,targetSum,root->val); 
       return result;  
    }
};
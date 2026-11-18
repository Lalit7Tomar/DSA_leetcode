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
    void recursion(TreeNode* root,vector<string>& ans,string s){
       string a=s;
       string b=s;
       if(root->left==nullptr && root->right==nullptr){
        ans.push_back(s);
       }
       if(root->left){
        a+="->";
        a+=to_string(root->left->val);
        recursion(root->left,ans,a);
       }
       if(root->right){
        b+="->";
        b+=to_string(root->right->val);
        recursion(root->right,ans,b);
       }
       

    }                       
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root==nullptr) return {};
        else if(root->left==nullptr && root->right==nullptr) return {to_string(root->val)};
        string s;
        
        s+=to_string(root->val);
        recursion(root,ans,s);
        return ans;
    }
};
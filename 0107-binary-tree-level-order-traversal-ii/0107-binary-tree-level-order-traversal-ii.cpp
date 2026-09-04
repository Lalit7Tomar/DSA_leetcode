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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
         queue<TreeNode*> q;
      q.push(root);
      vector<vector<int>> ans;
      if(root==nullptr) return {};
      ans.push_back({root->val});
      while(!q.empty()){
        int size=q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
         TreeNode* top=q.front();
          q.pop();

          if(top->left!=nullptr){
            q.push(top->left);
            level.push_back(top->left->val);
          }
          if(top->right!=nullptr){
            q.push(top->right);
            level.push_back(top->right->val);
          }
        }
       if(level.size()>0) ans.push_back(level);

      }
      for(int i=0;i<(ans.size()+1)/2;i++){
        vector<int> a=ans[i];
        vector<int> b=ans[ans.size()-1-i];
        ans[i]=b;
        ans[ans.size()-1-i]=a;
      }
      return ans;
    }
};
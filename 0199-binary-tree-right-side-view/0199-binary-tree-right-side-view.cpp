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
    vector<int> rightSideView(TreeNode* root) {
        /// level ordertraversal
        vector<int> a;
        queue<TreeNode*> q;
        if(root==nullptr) return {};
        q.push(root);
        while(!q.empty()){
            a.push_back(q.front()->val);
            int top=q.size();
            for(int i=0;i<top;i++){
               TreeNode* x=q.front();
               if(x->right) q.push(x->right);
               if(x->left) q.push(x->left);
               q.pop();
            }
        }
        return a;
    }
};
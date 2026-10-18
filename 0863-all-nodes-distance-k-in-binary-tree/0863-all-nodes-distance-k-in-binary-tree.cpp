/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root,unordered_map<int,vector<int>>& m){
      if(!root) return;
      if(root->left){
        m[root->val].push_back(root->left->val);
        m[root->left->val].push_back(root->val);
        dfs(root->left,m);
      }
      if(root->right){
        m[root->val].push_back(root->right->val);
        m[root->right->val].push_back(root->val);
        dfs(root->right,m);
      }
      

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int>> m;
        dfs(root,m);
        queue<int> q;
                set<int> s1;

        q.push(target->val);
        s1.insert(target->val);
        int occ=k;
        while(occ>0 && !q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                for(int j=0;j<m[q.front()].size();j++){
                   if(s1.find(m[q.front()][j])==s1.end()){
                    q.push(m[q.front()][j]);
                    s1.insert(m[q.front()][j]);
                }}
                q.pop();
            }
            occ--;
        }
        vector<int> ans;
        int f=q.size();
        for(int i=0;i<f;i++){
          ans.push_back(q.front());
          q.pop();
        }
        return ans;
    }
};
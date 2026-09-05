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
    void dfs(TreeNode* root,int rx,int ry,map<int,vector<pair<int,int>>>& m){
        
        m[ry].push_back({rx,root->val});
        if(root->left) dfs(root->left,rx+1,ry-1,m);
        if(root->right) dfs(root->right,rx+1,ry+1,m);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int rx=0;
        map<int,vector<pair<int,int>>> m;
        dfs(root,0,0,m);
        vector<vector<int>> ans;
        for (auto &kv : m) {
            auto &vec = kv.second;
            sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
                if (a.first != b.first) return a.first < b.first; // sort by row
                return a.second < b.second;                     
            });

            vector<int> colVals;
            for (auto &p : vec) colVals.push_back(p.second);
            ans.push_back(colVals);
        
    }
      return ans;
    }
};
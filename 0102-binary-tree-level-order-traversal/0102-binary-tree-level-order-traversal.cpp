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
   void helper(TreeNode* root, int curr, int level, std::vector<int>& u) {
    if (root == nullptr) return;

    if (curr == level) {
        u.push_back(root->val);
        return;
    }

    helper(root->left, curr + 1, level, u);
    helper(root->right, curr + 1, level, u);
}
  
  int levels(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + std::max(levels(root->left), levels(root->right));
}

   
    vector<vector<int>> levelOrder(TreeNode* root) {
        int level = levels(root);
    std::vector<std::vector<int>> ans;

    for (int i = 1; i <= level; i++) {
        std::vector<int> t;
        helper(root, 1, i, t);
        ans.push_back(t);
    }

    return ans;
    }
};
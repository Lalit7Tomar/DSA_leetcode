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
    int maxSum=INT_MIN;
   int pathsum(TreeNode* root) {
        if (root == nullptr) return 0;
        
        // Fix 2 & 3: Get left and right sums. If they are negative, treat them as 0.
        int leftSum = max(0, pathsum(root->left));
        int rightSum = max(0, pathsum(root->right));
        
        // Update the global max. 
        // A path can "curve" through the current node, using both left and right branches.
        maxSum = max(maxSum, leftSum + rightSum + root->val);
        
        // Fix 4: Return to the parent.
        // A path going UP to a parent can only include ONE branch (left OR right).
        return root->val + max(leftSum, rightSum); 
    }
    int maxPathSum(TreeNode* root) {
       pathsum(root);
      
       return maxSum;
    }
};
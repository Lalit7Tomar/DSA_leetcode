class Solution {
public:
    int diameter = 0;

    int depth(TreeNode* root) {
        if (!root) return 0;

        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);

        diameter = max(diameter, leftDepth + rightDepth);

        return 1 + max(leftDepth, rightDepth);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return diameter;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // lowest common ancestor
        if(root && ((root->val<=p->val && root->val>q->val) || (root->val<=q->val && root->val>p->val) || (root->val<p->val && root->val>=q->val) || (root->val<q->val && root->val>=p->val))){
            return root;
        }
        else if(root && (root->val<p->val && root->val<q->val)) return lowestCommonAncestor(root->right,p,q);
        else if(root){
            return lowestCommonAncestor(root->left,p,q);
        }
        return nullptr;
    }
};
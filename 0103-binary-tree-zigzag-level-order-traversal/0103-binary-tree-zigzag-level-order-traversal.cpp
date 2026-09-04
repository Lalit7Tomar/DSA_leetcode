class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       queue<TreeNode*> q;
       vector<vector<int>> ans;
       int a=1;
       
       if(root==nullptr) return {};
       if(root!=nullptr) ans.push_back({root->val});
       q.push(root);
       while(!q.empty()){
         vector<int> level;
         
            int f=q.size();
         for(int i=0;i<f;i++){
           TreeNode* t=q.front();
            if(t->left!=nullptr){
             level.push_back(t->left->val);
             q.push(t->left);
            }
            if(t->right!=nullptr){


            level.push_back(t->right->val);
            q.push(t->right);
            }
            q.pop();
         }
         if(a%2==0 && !level.empty()) ans.push_back(level);
         if (a % 2 == 1 && !level.empty()) {
    reverse(level.begin(), level.end());   // reverse in place
    ans.push_back(level);                  // then push the vector
}

         a++;
       } 
       return ans;
    }
};
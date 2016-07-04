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
    void search_left(TreeNode *root,vector<int>&left){
      if(root==NULL){
        left.push_back(-1);
        return;
      }
      search_left(root->left,left);
      search_left(root->right,left);
      left.push_back(root->val);
    }

    void search_right(TreeNode *root,vector<int>&right){
      if(root==NULL){
        right.push_back(-1);
        return;
      }
      search_right(root->right,right);
      search_right(root->left,right);
      right.push_back(root->val);
    }

    bool isSymmetric(TreeNode* root) {
      if(root==NULL) return true;
      vector<int>left,right;
      search_left(root->left,left);
      search_right(root->right,right);
      if(left.size()!=right.size()) return false;
      for(int i=0;i<left.size();i++){
        cout<<left[i]<<" "<<right[i]<<endl;
        if(left[i]!=right[i]) return false;
      }
      return true;
    }
};


class Solution {
public:
    bool Symmetric(TreeNode *left, TreeNode *right){
      if(left==NULL && right==NULL) return true;
      if(left && right && left->val == right->val) return Symmetric(left->left,right->right) && Symmetric(left->right,right->left);
      return false;
    }
    bool isSymmetric(TreeNode* root) {
      if(root==NULL) return true;
      return Symmetric(root->left,root->right);
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        queue<TreeNode*>lf,rt;
        if(root->left) lf.push(root->left);
        if(root->right) rt.push(root->right);
        TreeNode*l,*r;
        while(!lf.empty() && !rt.empty()){
          l=lf.front();lf.pop();
          r=rt.front();rt.pop();
          if(l==NULL && r==NULL) continue;
          if(l==NULL || r==NULL) return false;
          if(l->val != r->val) return false;
          lf.push(l->left);
          lf.push(l->right);
          rt.push(r->right);
          rt.push(r->left);
        }
        if(lf.empty() && rt.empty()) return true;
        return false;
    }
};

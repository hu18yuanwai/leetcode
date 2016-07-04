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
    bool isleast(TreeNode *root, int num){
      if(root==NULL) return true;
      else{
        if(root->val>=num) return false;
        return isleast(root->left,num) && isleast(root->right,num);
      }
    }

    bool isLarge(TreeNode *root, int num){
      if(root==NULL) return true;
      else{
        if(root->val<=num) return false;
        return isLarge(root->left,num) && isLarge(root->right,num);
      }
    }

    bool isValidBST(TreeNode* root) {
      if(root==NULL) return true;
      if(root->left==NULL && root->right==NULL) return true;
      if(root->left!=NULL && root->right==NULL){
        return isleast(root->left,root->val)&&(root->val>root->left->val)&&isValidBST(root->left);
      }
      if(root->left==NULL && root->right!=NULL){
        return isLarge(root->right,root->val)&&(root->val<root->right->val)&&isValidBST(root->right);
      }
      else{
        return isLarge(root->right,root->val)&&isleast(root->left,root->val)&&(root->val<root->right->val)&&isValidBST(root->right)&&(root->val>root->left->val)&&isValidBST(root->left);
      }
    }
};

class Solution {
public:
    bool isleast(TreeNode *root, int num){
      if(root==NULL) return true;
      if(root->val>num) return false;
      return isleast(root->left,num) && isleast(root->right,num);
    }

    bool isLarge(TreeNode *root, int num){
      if(root==NULL) return true;
      if(root->val<num) return false;
      return isLarge(root->left,num) && isLarge(root->right,num);
    }

    bool isValidBST(TreeNode* root) {
      if(root==NULL) return true;
      if(!isleast(root->left,root->val) || !isLarge(root->right,root->val)) return false;
      return isValidBST(root->left)&&isValidBST(root->right);
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
      if(root==NULL) return true;
      if(root->right==NULL && root->left==NULL) return true;
      return isValidBST_(root,LONG_LONG_MIN,LONG_LONG_MAX);
    }

    bool isValidBST_(TreeNode *root, long long min, long long max){
      if(root==NULL) return true;
      if(root->val<=min || root->val>=max) return false;
      return isValidBST_(root->left,min,root->val) && isValidBST_(root->right,root->val,max);
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
      if(root==NULL) return true;
      if(root->left==NULL && root->right==NULL) return true;
      vector<int>node;
      inOrderTraversal(root,node);
      for(int i=1;i<node.size();i++) if(node[i-1]>=node[i]) return false;
      return true;
    }
    void inOrderTraversal(TreeNode* root,vector<int>&node){
      if(root==NULL) return;
      inOrderTraversal(root->left,node);
      node.push_back(root->val);
      inOrderTraversal(root->right,node);
    }
};

class Solution {
public:
    TreeNode *pre=NULL;
    bool isValidBST(TreeNode* root) {
        if (root != NULL) {
            if (!isValidBST(root->left)) return false;
            if (pre != NULL && root->val <= pre->val) return false;
            pre = root;
            return isValidBST(root->right);
        }
        return true;
     }
};

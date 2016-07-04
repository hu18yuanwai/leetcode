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
  vector<TreeNode*> helper(int begin,int end){
    vector<TreeNode*>ret;
    if(begin>end) ret.push_back(NULL);

    else if(begin==end){
      ret.push_back(new TreeNode(begin));
    }

    else{
      for(int i=begin;i<=end;i++){
        vector<TreeNode*>left=helper(begin,i-1);
        vector<TreeNode*>right=helper(i+1,end);
        for(int k=0;k<left.size();k++){
          for(int j=0;j<right.size();j++){
            TreeNode* root=new TreeNode(i);
            root->left=left[k];
            root->right=right[j];
            ret.push_back(root);
          }
        }
      }
    }
    return ret;
  }

  vector<TreeNode*> generateTrees(int n) {
      return helper(1,n);
    }
};

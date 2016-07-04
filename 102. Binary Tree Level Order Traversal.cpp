class Solution {
public:
    void help_levelOrder(TreeNode* root,vector<vector<int>>&ret, int level){
      if(root==NULL) return;
      if(ret.size()<level+1){
         vector<int> a;
         ret.push_back(a);
       }
      ret[level].push_back(root->val);
      help_levelOrder(root->left,ret,level+1);
      help_levelOrder(root->right,ret,level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>>ret;
      help_levelOrder(root,ret,0);
      return ret;
    }
};

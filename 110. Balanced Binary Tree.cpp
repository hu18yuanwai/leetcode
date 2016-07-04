int height(TreeNode* root){
  if(root==NULL) return 0;
  if(root->left==NULL&&root->right==NULL) return 1;
  if(root->left==NULL&&root->right!=NULL) return 1+height(root->right);
  if(root->left!=NULL&&root->right==NULL) return 1+height(root->left);
  return 1+(height(root->left)>height(root->right)?height(root->left):height(root->right));
}

bool isBalanced(TreeNode* root) {
  if(root==NULL) return true;
  if(abs(height(root->left)-height(root->right))>1) return false;
  return isBalanced(root->left)&&isBalanced(root->right);
}

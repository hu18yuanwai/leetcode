#include <iostream>
using namespace std; 

struct TreeNode {
int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

int max(TreeNode* p,TreeNode* q){
	if(p->val>q->val)
		return p->val;
	return q->val;
}

int min(TreeNode* p,TreeNode* q){
	if(p->val<q->val)
		return p->val;
	return q->val;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if(root==NULL || p==NULL || q==NULL)
		retur NULL;
	else if(root->val < max(p,q) && root->val > min(p,q))
		return root;
	else if(root->val > max(p,q))
		return lowestCommonAncestor(root->left,p,q);
	else if(root->val < min(p,q))
		return lowestCommonAncestor(root->right,p,q);
	else if(root->val == p->val)
		return p;
	else if(root ->val == q->val)
		return q;
}

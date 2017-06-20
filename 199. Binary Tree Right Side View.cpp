/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // the worry anser
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        rightSideView_iter(root,ret);
        return ret;
    }
private:
	void rightSideView_iter(TreeNode*root, vector<int>&ret){
		if(root==nullptr) return;
		ret.push_back(root->val);
		if(root->right){
			rightSideView_iter(root->right,ret);
		}
		else if(root->left){
			rightSideView_iter(root->left,ret);
		}
	}
};

//

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
    	vector<int> ret;
    	if(root==nullptr) return ret;
    	ret.push_back(root->val);
    	vector<int> le,rig;
    	if(root->left)
    		le = rightSideView(root->left);
    	if(root->right)
    		rig = rightSideView(root->right);
    	for(int i=0;i<rig.size();i++)	ret.push_back(rig[i]);
    	if(rig.size()< le.size()){
    		for(int i=rig.size();i<le.size();i++)
    			ret.push_back(le[i]);
    	}
    	return ret;
    }
};
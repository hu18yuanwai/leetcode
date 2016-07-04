/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct NewNode{
	TreeNode * node;
	int height;
	NewNode(TreeNode *tnode, int theight):node(tnode),height(theight){}
};
class Solution {
public:
	int getHeight(TreeNode* root){
		if(root==NULL) return 0;
		int l=getHeight(root->left),r=getHeight(root->right);
		return 1+max(l,r);
	}

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int h=getHeight(root);
        vector<vector<int>>ret;
        for(int i=0;i<h;i++){
        	vector<int>temp;
        	ret.push_back(temp);
        }
        if(h==0) return ret;
        queue<TreeNode*> tree;
        queue<int> height;
        tree.push(root);
        height.push(1);
        while(!tree.empty()){
        	TreeNode *cur=tree.front();
        	int hei=height.front();
        	ret[h-hei].push_back(cur->val);
        	if(cur->left){
        		tree.push(cur->left);
        		height.push(hei+1);
        	}
        	if(cur->right){
        		tree.push(cur->right);
        		height.push(hei+1);
        	}
        	tree.pop();
        	height.pop();
        }

        return ret;
    }
};



//di gui
class Solution
{
public:
    vector<vector<int> > result;

    void levelTra(TreeNode *root, int level)
    {
        if(root == NULL)
            return;
        if(level == result.size())
        {
            vector<int> v;
            result.push_back(v);
        }
        result[level].push_back(root->val);
        levelTra(root->left, level+1);
        levelTra(root->right, level+1);
    }

    vector<vector<int> > levelOrderBottom(TreeNode *root) 
    {
        levelTra(root, 0);
        return vector<vector<int> >(result.rbegin(), result.rend());
    }
};
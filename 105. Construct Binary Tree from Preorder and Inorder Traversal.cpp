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
	TreeNode* constructTree(vector<int>& preorder,int startP,int endP,
		vector<int>& inorder,int startI,int endI){
		int rootValue= preorder[startP];
		TreeNode* root = new TreeNode(rootValue);
		if(startP == endP ){
			if(startI == endI && preorder[startP]==inorder[startI])
				return root;
			else{
				cout<<"Invalid input"<<endl;
				return NULL;
			}
		}
		
		int index = startI;
		while(index<=endI && inorder[index]!=rootValue)
			index++;
		
		int length = index - startI;
		int leftPreEnd = startP + length;
		if(length>0){
			root->left = constructTree(preorder,startP+1,leftPreEnd,inorder,startI,index-1);
		}
		if(length<endP - startP){
			root->right = constructTree(preorder,leftPreEnd+1,endP,inorder,index+1,endI);
		}
		return root;
	}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0 || inorder.size()==0 ||
         preorder.size()!=inorder.size())
        	return NULL;
        return constructTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};
class Solution {
public:
		TreeNode* constructTree(vector<int>& preorder,int startP,int endP,
		vector<int>& inorder,int startI,int endI){
		int rootValue= inorder[endI];
		TreeNode* root = new TreeNode(rootValue);
		if(startP == endP ){
			if(startI == endI && preorder[startP]==inorder[startI])
				return root;
			else{
				cout<<"Invalid input"<<endl;
				return NULL;
			}
		}
		
		int index = startP;
		while(index<=endP && preorder[index]!=rootValue)
			index++;
		
		int length = index - startP;
		if(length>0){
			root->left = constructTree(preorder,startP,index-1,inorder,startI,startI+length-1);
		}
		if(length<endP - startP){
			root->right = constructTree(preorder,index+1,endP,inorder,startI+length,endI-1);
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
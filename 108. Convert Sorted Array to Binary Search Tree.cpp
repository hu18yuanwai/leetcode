class Solution {
public:
	TreeNode* construct_tree(vector<int>& nums,int start,int end){
		int mid=(end+start)>>1;
		int rootValue = nums[mid];
		TreeNode* root = new TreeNode(rootValue);
		if(start == end) return root;
		if(start<mid)
			root->left = construct_tree(nums,start,mid-1);
		if(mid<end)
			root->right = construct_tree(nums, mid+1,end);
		return root;
	}

    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	if(nums.size()==0) return NULL;
        return construct_tree(nums,0,nums.size()-1);
    }
};
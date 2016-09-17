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
    void dfs(TreeNode* root, string tempsum, int &ret){
        if(root == NULL){
            ret+=0;
            return;
        }
        tempsum = tempsum + (char)('0'+root ->val);
        if(root->left == NULL && root->right == NULL){
            ret = ret+stoi(tempsum);
            return;
        }
        if(root->left)
            dfs(root->left,tempsum,ret);
        if(root->right)
            dfs(root->right,tempsum,ret);
    }

    int sumNumbers(TreeNode* root) {
        int ret = 0;
        string tempsum;
        dfs(root,tempsum,ret);
        return ret;
    }
};

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
    void flatten(TreeNode* root) {
        if(root==nullptr) return;
        if(root->left == nullptr && root->right == nullptr) return;
        TreeNode* curLeft = nullptr,*curRight = nullptr;
        if(root->left!=nullptr) {
            flatten(root->left);
            curLeft = root->left;
            while(curLeft->right) curLeft=curLeft->right;
        }
        if(root->right!=nullptr){
            flatten(root->right);
            curRight = root->right;
        }
        if(curLeft!=nullptr) {root->right = root->left; root->left=NULL;}
        if(curRight!=nullptr){
            if(curLeft!=nullptr){
                curLeft->right = curRight;
            }
            else{
                root->right = curRight;
            }
        }
    }
};



class Solution {
public:
    void flatten(TreeNode *root) {
        if(root == NULL) return;
        while(root){
            if(root->left){
                TreeNode *pre = root->left;
                while(pre->right)
                    pre = pre->right;
                    pre->right = root->right;
                    root->right = root->left;
                    root->left = NULL;
                }
                root = root->right;
        }
    }
};

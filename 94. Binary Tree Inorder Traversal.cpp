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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>re;
        if(root==NULL)
            return re;
        vector<int>left=inorderTraversal(root->left);
        vector<int>right=inorderTraversal(root->right);
        for(int i=0;i<left.size();i++){
            re.push_back(left[i]);
        }
        re.push_back(root->val);
        for(int i=0;i<right.size();i++){
            re.push_back(right[i]);
        }
        return re;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ret;
        stack<TreeNode*> mySta;
        auto p = root;
        while(p!=nullptr){
            mySta.push(p);
            p=p->left;
        }
        while(!mySta.empty()){
            auto node = mySta.top();
            mySta.pop();
            ret.push_back(node->val);
            if(node->right!=nullptr){
                auto p =node->right;
                while(p!=nullptr){
                    mySta.push(p);
                    p=p->left;
                }
            }
        }
        return ret;
    }
};

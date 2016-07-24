/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //递归
 class Solution
{
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> res;
        if (root == nullptr)
        {
            return res;
        }

        res.push_back(root->val);
        auto v1 = preorderTraversal(root->left);
        res.insert(res.end(), v1.begin(), v1.end());
        auto v2 = preorderTraversal(root->right);
        res.insert(res.end(), v2.begin(), v2.end());
        return res;
    }
};

//非递归
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ret;
        stack<TreeNode*> mySta;
        mySta.push(root);
        while(!mySta.empty()){
            auto p = mySta.top();
            mySta.pop();
            if(p!=nullptr){
                ret.push_back(p->val);
                mySta.push(p->right);
                mySta.push(p->left);
            }
        }
        return ret;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//http://www.jianshu.com/p/e61d44f3dc33
 class Solution
{
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty())
        {
            auto p = nodes.top();
            nodes.pop();
            if (p != nullptr)
            {
                res.push_back(p->val);
                nodes.push(p->left);
                nodes.push(p->right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> nodeSta;
        TreeNode* p =root;
        unordered_map<TreeNode*,int> tag;
        while(p!=NULL || !nodeSta.empty()){
            while(p!=NULL){
                nodeSta.push(p);
                tag[nodeSta.top()]=0;
                p=p->left;
            }

            while(!nodeSta.empty() && tag[nodeSta.top()]==1){
                p= nodeSta.top();
                nodeSta.pop();
                ret.push_back(p->val);
            }

            if(!nodeSta.empty()){
                tag[nodeSta.top()]=1;
                p=nodeSta.top();
                p=p->right;
            }
            else break;
        }
    }
};

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
    struct Node{
        TreeNode *node;
        int level;
        Node(TreeNode *newnode,int n):node(newnode),level(n){}
    };

    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<Node> nodeQue;
        nodeQue.push( Node(root,1));
        while(!nodeQue.empty()){
            Node cur= nodeQue.front();
            nodeQue.pop();
            if(cur.node->left==nullptr && cur.node->right==nullptr)
                return cur.level;
            if(cur.node->left!=nullptr)
                nodeQue.push(Node(cur.node->left,cur.level+1));
            if(cur.node->right!=nullptr)
                nodeQue.push(Node(cur.node->right,cur.level+1));
        }
        return -1;
    }
};


class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        if(root->left==nullptr && root->right==nullptr) return 1;
        int minDep=INT_MAX;
        if(root->left!=nullptr) minDep = min(minDepth(root->left)+1,minDep);
        if(root->right!=nullptr) minDep = min(minDepth(root->right)+1,minDep);
        return minDep;
    }
};

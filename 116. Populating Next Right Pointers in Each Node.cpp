/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if(root!=NULL){
        	queue<TreeLinkNode*> nodeQ;
        	queue<int> level;
        	nodeQ.push(root);
        	level.push(0);
        	TreeLinkNode* pre=NULL;
        	while(!nodeQ.empty()){
        		TreeLinkNode* cur=nodeQ.pop();
        		if(pre==NULL){
        			pre=cur;
        		}
        	}
        }
    }
};
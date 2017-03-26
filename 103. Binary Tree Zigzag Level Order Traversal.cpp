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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> >ret;
        if(root==nullptr) return ret;
        queue< pair<TreeNode*,int> > myQue;
        typedef pair<TreeNode*,int> mkpair;
        myQue.push(mkpair(root,0));
        int curLevel = -1;
        vector<int> temp;
        while(!myQue.empty()){
            mkpair tempair = myQue.front();
            myQue.pop();
            if(tempair.second > curLevel) { vector<int>().swap(temp); curLevel++;}
            TreeNode* curNode = tempair.first;
            temp.push_back(curNode->val);
            if(curNode->left) myQue.push(mkpair(curNode->left,tempair.second+1));
            if(curNode->right) myQue.push(mkpair(curNode->right,tempair.second+1));
            if(myQue.empty() || myQue.front().second > curLevel){
                ret.push_back(temp);
            }
        }
        for(int i=0;i<ret.size();i++){
            if(i%2==1){
                reverse(ret[i].begin(),ret[i].end());
            }
        }
        return ret;
    }
};

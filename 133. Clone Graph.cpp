/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==nullptr) return node;
        UndirectedGraphNode* ret;
        stack<UndirectedGraphNode*> mystack;
        map<UndirectedGraphNode*,UndirectedGraphNode*> mymap;
        mystack.push(node);
        ret = new UndirectedGraphNode(node->label);
        mymap[node]=ret;
        while(!mystack.empty()){
            UndirectedGraphNode* temp = mystack.top();
            mystack.pop();
            UndirectedGraphNode* curCopy = mymap[temp];
            for(int i=0;i<(temp->neighbors).size();i++){
                if(mymap.find(temp->neighbors[i])==mymap.end() ){
                    mymap[temp->neighbors[i]] = new UndirectedGraphNode(temp->neighbors[i]->label);
                    mystack.push(temp->neighbors[i]);
                }
                curCopy->neighbors.push_back(mymap[temp->neighbors[i]]);
            }
        }
        return ret;
    }
};
class Solution {
public:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
       if (!node) return node;
       if(hash.find(node) == hash.end()) {
           hash[node] = new UndirectedGraphNode(node -> label);
           for (auto x : node -> neighbors) {
                (hash[node] -> neighbors).push_back( cloneGraph(x) );
           }
       }
       return hash[node];
    }
};

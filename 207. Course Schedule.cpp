class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> Indegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            Indegree[prerequisites[i].second]++;
        }

        queue<int> myque;

        for(int i=0;i<numCourses;i++){
            if(Indegree[i]==0){
                myque.push(i);
            }
        }

        while(!myque.empty()){
            int cur = myque.front();
            myque.pop();

            for(int i=0;i<prerequisites.size();i++){
                if(prerequisites[i].first==cur){
                    Indegree[prerequisites[i].second]--;
                    if(Indegree[prerequisites[i].second]==0){
                        myque.push(prerequisites[i].second);
                    }
                }
            }
        }

        for(int i=0;i<Indegree.size();i++){
            if(Indegree[i]!=0) return false;
        }
        return true;
    }
};









class Solution {
public:
    void dfs(int cur, unordered_map<int,vector<int> >& graph, vector<int> &visit, bool&iscircle){
        if(graph[cur].size() == 0) return;
        for(int i=0;i<graph[cur].size();i++){
            for(int j=0;j<visit.size();j++){
                if(visit[j] == graph[cur][i]){
                    iscircle = true;
                    return;
                }
            }

            visit.push_back(graph[cur][i]);
            dfs(graph[cur][i],graph,visit,iscircle);
            visit.pop_back();
        }
    }

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(prerequisites.size()==0) return true;

        unordered_map<int,vector<int> > graph;
        for(int i=0;i<prerequisites.size();i++){
            int cur = prerequisites[i].first, pre = prerequisites[i].second;
            graph[cur].push_back(pre);
        }

        for(int i=0;i<numCourses;i++){
            vector<int>visit;
            visit.push_back(i);
            bool iscircle = false;
            dfs(i,graph,visit,iscircle);
            if(iscircle) return false;
        }
        return true;
    }
};

class Solution {
public:
  void backStrack(vector<vector<int>>& ret,vector<int>& candidates,vector<int>& cur,int target,int N){
    if(target==0) ret.push_back(cur);
    else{
      for(int i=N;i<candidates.size() && candidates[i]<=target;i++){
        if(i!=N && candidates[i]==candidates[i-1]) continue;
        cur.push_back(candidates[i]);
        backStrack(ret,candidates,cur,target-candidates[i],i+1);
        cur.pop_back();
      }
    }
  }

  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      vector<vector<int>> ret;
      sort(candidates.begin(),candidates.end());
      vector<int>cur;
      backStrack(ret,candidates,cur,target,0);
      return ret;
  }
};

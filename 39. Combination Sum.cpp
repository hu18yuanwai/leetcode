class Solution {
public:
  void backStrack(vector<vector<int>>& ret, vector<int>& temp,vector<int>& candidates,int start,int sum){
    if(sum==0){
      ret.push_back(temp);
    }
    else{
      for(int i=start;i<candidates.size();i++){
        temp.push_back(candidates[i]);
        if(sum>=candidates[i]){
          backStrack(ret,temp,candidates,i,sum-candidates[i]);
        }
        temp.pop_back();
      }
    }
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> ret;
      sort(candidates.begin(),candidates.end());
      vector<int>temp;
      backStrack(ret,temp,candidates,0,target);
      return ret;
  }
};

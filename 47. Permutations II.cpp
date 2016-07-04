class Solution {
public:
  bool swapIsOk(vector<int> &nums, int n,int i){
    for(int j=n;j<i;j++) if(nums[j]==nums[i]) return false;
    return true;
  }

  void backTrack(vector<int> &nums,vector<vector<int>> &ret,int n){
      if(n==nums.size()-1){
        ret.push_back(nums);
      }
      else{
        for(int i=n;i<nums.size();i++){
          if(swapIsOk(nums,n,i)){
            swap(nums[n],nums[i]);
            backTrack(nums,ret,n+1);
            swap(nums[n],nums[i]);
        }
        }
      }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
      vector<vector<int>> ret;
      backTrack(nums,ret,0);
      return ret;
    }
};

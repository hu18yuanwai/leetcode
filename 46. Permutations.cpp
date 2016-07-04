class Solution {
public:
void backTrack(vector<int> &nums,vector<vector<int>> &ret,int n){
    if(n==nums.size()-1){
      ret.push_back(nums);
    }
    else{
      for(int i=n;i<nums.size();i++){
        swap(nums[n],nums[i]);
        backTrack(nums,ret,n+1);
        swap(nums[n],nums[i]);
      }
    }
  }

  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ret;
    backTrack(nums,ret,0);
    return ret;
  }
};

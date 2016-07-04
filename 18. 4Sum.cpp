vector<vector<int> > fourSum(vector<int>& nums, int target) {
  sort(nums.begin(),nums.end());
  vector<vector<int> >result;
  if(nums.size()<4) return result;
  for(int i=0;i<nums.size()-3;i++){
    //if(nums[i]>target) break;
    if(i>0 && nums[i]==nums[i-1]) continue;

    for(int j=i+1;j<nums.size()-2;j++){
      //if(nums[i]+nums[j]>target) break;
      if(j>i+1 && nums[j]==nums[j-1]) continue;

      int left=j+1,right=nums.size()-1;
      while(left<right){
        if(nums[left]+nums[right]==target-nums[i]-nums[j]){
          vector<int>re;
          re.push_back(nums[i]);
          re.push_back(nums[j]);
          re.push_back(nums[left]);
          re.push_back(nums[right]);
          result.push_back(re);
          left++;
  		  while(left<nums.size() && nums[left]==nums[left-1]){
  			left++;
  		  }
  		 while(right-1>=0 && nums[right]==nums[right-1]){
  			right--;
  		  }
  		}
        else if(nums[left]+nums[right]<target-nums[i]-nums[j]) left++;
        else right--;
      }
    }
  }
  return result;
}

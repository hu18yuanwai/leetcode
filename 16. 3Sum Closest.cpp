int threeSumClosest(vector<int>& nums, int target) {
  sort(nums.begin(),nums.end());
  int result=nums[0]+nums[1]+nums[2];
  for(int i=0;i<nums.size()-2;i++){
    if(i>0 && nums[i]==nums[i-1]) continue;
    int left=i+1,right=nums.size()-1;
    while(left<right){
      if(nums[left]+nums[right]==target-nums[i]){
        return target;
      }
      else if(nums[left]+nums[right]<target-nums[i]){
         if(target-nums[i]-nums[left]-nums[rigth]<result) result=nums[i]+nums[left]+nums[rigth];
         left++;
       }
     else{
       if(nums[i]+nums[left]+nums[rigth]-target<result) result=nums[i]+nums[left]+nums[right];
         right--;
    }
   }
  }
  return result;
}

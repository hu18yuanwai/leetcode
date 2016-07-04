int searchInsert(vector<int>& nums, int target) {
if(target<=nums[0])
  return 0;
if(target>nums[nums.size()-1])
  return nums.size();

int high=nums.size()-1,low=0;
while(high>low){
  int mid=(high+low)/2;
  if(nums[mid]==target|| ( nums[mid-1])<target&&nums[mid]>=target)
    return mid;
  else if((nums[mid+1]>=target&&nums[mid]<target))
    return mid+1;
  else if(nums[mid]>target)
    high=mid;
  else if(nums[mid]<target)
    low=mid;
}
}

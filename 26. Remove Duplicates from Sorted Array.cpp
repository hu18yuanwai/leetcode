int removeDuplicates(vector<int>& nums) {
    if(nums.size()==0) return 0;
    if(nums.size()==1) return 1;
    int curNum=nums[0];
    int pos1=1,pos2=1;
    while(pos1<nums.size()){
      while(nums[pos1]==curNum) pos1++;
      curNum=nums[pos2]=nums[pos1];
      pos2++;
    }
    return pos2-1;
}

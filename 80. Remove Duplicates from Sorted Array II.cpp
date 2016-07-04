class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      if(nums.size()==0) return 0;
      int curNum=nums[0];
      int pos1=0,pos2=0;
      while(pos2<nums.size()){
        int count=0;
        while(nums[pos2]==curNum &&pos2<nums.size()){
          count++;
          pos2++;
        }
        nums[pos1++]=curNum;
        if(count>1) nums[pos1++]=curNum;
        curNum=nums[pos2];
      }
      return pos1;
    }
};

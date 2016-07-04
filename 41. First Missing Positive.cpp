class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==0) return 1;
        for(int i=0;i<nums.size();i++) nums[i]=nums[i]-1;
        for(int i=0;i<nums.size();i++){
          while(nums[i]>=0 && nums[i]<nums.size() && nums[i]!=i && nums[i]!=nums[nums[i]]){
            int temp=nums[i];
            nums[i]=nums[temp];
            nums[temp]=temp;
          }
        }

        for(int i=0;i<nums.size();i++)
          if(nums[i]!=i) return i+1;

        return nums.size()+1;
    }
};

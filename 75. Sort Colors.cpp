//two pass algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {
      int count0=0,count1=0;
      for(int i=0;i<nums.size();i++){
        if(nums[i]==0) count0++;
        else if(nums[i]==1) count1++;
        else continue;
      }
      for(int i=0;i<count0;i++) nums[i]=0;
      for(int i=count0;i<count0+count1;i++) nums[i]=1;
      for(int i=count0+count1;i<nums.size();i++) nums[i]=2;
    }
};

//one pass algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {
      int left=0,right=nums.size()-1;
      int i=0;
      while(i<=right){
        if(nums[i]==0){
          swap(nums[i++],nums[left++]);
          i++;
          left++;
        }
        else if(nums[i]==1){
          i++;
        }
        else{
          swap(nums[right],nums[i]);
          right--;
        }
      }
    }
};

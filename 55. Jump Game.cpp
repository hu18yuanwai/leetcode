class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool iszero=false;
        for(int i=0;i<nums.size();i++) if(nums[i]==0) iszero=true;
        if(iszero==false) return true;
        int start=0,end=0,old=0;
        bool ret=false;
        while(end<nums.size()-1 ){
          old=end;
          for(int i=start;i<=old;i++){
            if(i+nums[i]>end){
              end=i+nums[i];
              if(end>=nums.size()) return true;
            }
          }
          if(old==end) return false;
        }
        return true;
    }
};


class Solution {
   public:
       bool canJump(vector<int>& nums) {
           // 记录历史跳最远距离
           int n=nums.size();
           int distance = 0;
           for(int i = 0;i < n && i <= distance;++i){
               // A[i]+i当前跳最远距离 distance为i之前跳最远距离
               distance = max(A[i]+i,distance);
           }//for
           if(distance < n-1){
               return false;
           }//if
           return true;
       }
   };

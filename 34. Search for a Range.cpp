class Solution {
public:
//[8,8,8,8,8,8] target = 8
    vector<int> searchRange(int A[], int n, int target) {
        int start = 0, end = n - 1, mid = -1;
        vector<int> result;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (A[mid] >= target) {
                end = mid - 1;
            } else {
                start = start + 1;
            }
        }//根据mid的情况移动end, 最后end必然是比target小的第一个数
        result.push_back(end + 1);
        start = 0, end = n - 1, mid = -1;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (A[mid] <= target) {
                start = start + 1;
            } else {
                end = mid - 1;
            }
        }//根据mid的情况移动start, 最后start必然是比target大的第一个数
        result.push_back(start - 1);
        if (result[0] > result[1])  result = {-1, -1}; //一开始没有想到这个检验，检验当start > end时，说明找不到target
        return result;
    }
};


int binary_search(std::vector<int>& nums,int low,int high,int target){
  if(low>high) return -1;
  int start=low,end=high;
  while(start<=end){
      int mid=start+((end-start)>>1);
      if(nums[mid]>target) end=mid-1;
      else if(nums[mid]<target) start=mid+1;
      else return mid;
  }
  return -1;
}

vector<int> searchRange(vector<int>& nums, int target) {
  vector<int>re(2);
  int index=binary_search(nums,0,nums.size()-1,target);
  if(index==-1){
    re[0]=re[1]=-1;
  }
  else{
    int start1=index;
    while(1){
      int tem=binary_search(nums,0,start1-1,target);
      if(tem==-1) break;
      start1=tem;
    }
    int start2=index;
    while(1){
      int tem=binary_search(nums,start2+1,nums.size()-1,target);
      if(tem==-1) break;
      start2=tem;
    }
    cout<<index<<" "<<start1<<" "<<start2<<endl;
    if(start1==-1 && start2==-1){
      re[0]=re[1]=index;
    }
    else if(start1==-1 && start2!=-1){
      re[0]=index;
      re[1]=start2;
    }
    else if(start1!=-1 && start2==-1){
      re[0]=start1;
      re[1]=index;
    }
    else{
      re[0]=start1;
      re[1]=start2;
    }
  }
  return re;
}

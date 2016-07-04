int binary_search(vector<int>&nums,int begin,int end,int key){
int left=begin,right=end;

while(left<=right){
 int mid=left+((right-left)>>2);
 if(nums[mid]>key)
   right=mid-1;
 else if(nums[mid]<key)
   left=mid+1;
 else
   return mid;
}

return -1;
}

int search(vector<int>& nums,int key) {
     int min=0,max=nums.size()-1;

     if(nums[min]<=nums[max])
         return binary_search(nums,0,nums.size()-1,key);

     while(nums[min]>nums[max]){
       int mid=min+((max-min)>>2);
       //cout<<mid<<endl;
       if(nums[mid]>nums[max]&&nums[mid]>=nums[min]){
         min=mid+1;
   }

   else if(nums[mid]<nums[min]&&nums[mid]<nums[max]){
     max=mid;
   }

 }

 int search1=binary_search(nums,0,min-1,key);
 if(search1!=-1)
   return search1;
 int search2=binary_search(nums,min,nums.size(),key);
 if(search2!=-1)
   return search2;
 return -1;
 }

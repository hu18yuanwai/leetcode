double iterFindMe(vector<int>& nums1,int start1,vector<int>& nums2,int start2,int k){
  if(nums1.size()-start1>nums2.size()-start2){
    return iterFindMe(nums2,start2,nums1,start1,k);
  }
  if(nums1.size()-start1==0){
    return nums2[k-1];
  }
  if(k==1){
    return min(nums1[start1],nums2[start2]);
  }
  int pos1=min(k/2,(int)nums1.size()),pos2=k-pos1;
  if(nums1[start1+pos1-1]<nums2[start2+pos2-1]){
    return iterFindMe(nums1,start1+pos1,nums2,start2,k-pos1);
  }
  else if(nums1[start1+pos1-1]>nums2[start2+pos2-1]){
    return iterFindMe(nums1,start1,nums2,start2+pos2,k-pos2);
  }
  else{
    return nums1[start1+pos1-1];
  }
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int len1=nums1.size(),len2=nums2.size(),len=len1+len2;
    if(len & 1){
      return iterFindMe(nums1,0,nums2,0,len/2+1);
    }
    else{
      return (iterFindMe(nums1,0,nums2,0,len/2+1)+iterFindMe(nums1,0,nums2,0,len/2))/2;
    }
}

int removeElement(vector<int>& nums, int val) {
       vector<int>::iterator it= nums.begin();
       while(it!=nums.end()){
           if(*it==val){
               it=nums.erase(it);
           }
           else{
               it++;
           }
       }
       return nums.size();
}

int removeElement(vector<int>& nums, int val) {
  int pos1=0,pos2=nums.size()-1,count=0;
  for(int i=0;i< nums.siez();i++) if(nums[i]==val) count++;
  while(pos1<pos2){
    while(nums[pos1]!=val && pos1< nums.size()) pos1++;
    while(nums[pos2]==val&& pos2< nums.size()) pos2--;
    nums[pos1]=nums[pos2];
    pos1++;
    pos2--;
  }
  return nums.size()-count;
}

class Solution {
public:
   int threeSumClosest(vector<int>& nums, int target) {
  sort(nums.begin(),nums.end());
  int result=nums[0]+nums[1]+nums[2];
  for(int i=0;i<nums.size()-2;i++){
    if(i>0 && nums[i]==nums[i-1]) continue;
    int left=i+1,right=nums.size()-1;
    while(left<right){
      if(nums[left]+nums[right]==target-nums[i]){
        return target;
      }
      else if(nums[left]+nums[right]<target-nums[i]){
         if(target-nums[i]-nums[left]-nums[right]<abs(result-target)) result=nums[i]+nums[left]+nums[right];
         left++;
       }
     else{
       if(nums[i]+nums[left]+nums[right]-target<abs(result-target)) result=nums[i]+nums[left]+nums[right];
         right--;
    }
   }
  }
  return result;
}
};


class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int differ = numeric_limits<int>::max();
        sort(nums.begin(), nums.end());

        for (int i = 0; i + 2 < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])  // pass duplicates.
            {
                continue;
            }

            auto diff = twoSumClosest(nums, i + 1, target - nums[i]);
            if (abs(diff) < abs(differ))
            {
                differ = diff;
            }
        }
        return target + differ;
    }

private:
    int twoSumClosest(const vector<int> &nums, int pos, int target)
    {
        int differ = numeric_limits<int>::max();
        for (int i = pos, j = (int) nums.size() - 1; i < j;)
        {
            if (i > pos && nums[i] == nums[i - 1])  // pass duplicates.
            {
                i++;
                continue;
            }
            else if (j < nums.size() - 1 && nums[j] == nums[j + 1])  // pass duplicates.
            {
                j--;
                continue;
            }

            auto sum = nums[i] + nums[j];
            if (abs(sum - target) < abs(differ))
            {
                differ = sum - target;
            }

            if (sum < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return differ;
    }
};

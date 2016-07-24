class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return nums[0]*nums[1];

    }
};

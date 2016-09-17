class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorResult = 0;
        for(int i=0;i<nums.size();i++) xorResult= xorResult^nums[i];
        vector<int> ret(2,0);

        int find1 = 1;
        while ((xorResult&find1) == 0) find1 = find1 << 1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]&find1){
                ret[0]=ret[0]^nums[i];
            }
            else{
                ret[1]=ret[1]^nums[i];
            }
        }
        return ret;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> mymap;
        for(int i=0;i<nums.size();i++) mymap[nums[i]]++;
        for(int i=0;i<nums.size();i++) if(mymap[nums[i]]==1) return nums[i];
        return -1;
    }
};


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i=0; i< 32; i++) {
            int count = 0;
            int mask = 1 << i;
            for ( int j =0; j<nums.size();j++){
                if ( nums[j] & mask) count++;
            }
            if(count%3) result|=mask;
        }
        return result;
    }
};

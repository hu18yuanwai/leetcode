class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;
        if(numbers.size()<2) return ret;
        int pos1 = 0, pos2 = numbers.size()-1;

        while(pos1<pos2){
            if(nums[pos1]+nums[pos2] == target){
                ret.push_back(pos1+1);
                ret.push_back(pos2+1);
                break;
            }

            else if(nums[pos1]+nums[pos2] < target){
                pos2--;
            }
            else{
                pos1++;
            }
        }
    }
};

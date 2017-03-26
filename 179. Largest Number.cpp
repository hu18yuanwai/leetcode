class Solution {
public:
    static bool cmp(int a, int b)
    {
        string strA = to_string(a);
        string strB = to_string(b);
        return (strA + strB > strB + strA);
    }

    string largestNumber(vector<int>& nums) {
        string ret;
        if(nums.size()==0) return ret;
        sort(nums.begin(),nums.end(),cmp);
        for(int i=0;i<nums.size();i++){
            ret+=to_string(nums[i]);
        }
        if(nums[0]==0) return to_string(0);
        else return ret;
    }
};

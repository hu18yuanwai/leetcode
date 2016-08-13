class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        vector<int>temp;
        for(int i = nums.size()-k;i <= nums.size()-1;i++){
            temp.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            temp.push_back(nums[i]);
        }
        nums = temp;
    }
};


class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        if (nums.empty())
        {
            return;
        }

        auto n = nums.size();
        k %= n;
        vector<int> rotatedNums(nums.begin() + n - k, nums.end());
        rotatedNums.insert(rotatedNums.end(), nums.begin(), nums.begin() + n - k);
        nums = rotatedNums;
    }
};


class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k %= n;
        reverse(nums, nums+(n-k));
        reverse(nums+(n-k), nums+n);
        reverse(nums, nums+n);
    }
};

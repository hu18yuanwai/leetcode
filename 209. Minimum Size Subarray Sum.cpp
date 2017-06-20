#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        if(len<=0) return 0;
        int i=0,j=0,curSum=0, minLen = INT_MAX;
        while(j<len){
            curSum+=nums[j++];
            while(curSum>=s){
                minLen = min(minLen,j-i);
                curSum-=nums[i++];
            }
        }

        return minLen==INT_MAX?0:minLen;
    }
};

class Solution2 {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> sums = accumulate(nums);
        int n = nums.size(), minlen = INT_MAX;
        for (int i = 1; i <= n; i++) {
            if (sums[i] >= s) {
                int p = upper_bound(sums, 0, i, sums[i] - s);
                if (p != -1) minlen = min(minlen, i - p + 1);
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
private:
    vector<int> accumulate(vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(n + 1, 0);
        for (int i = 1; i <= n; i++)
            sums[i] = nums[i - 1] + sums[i - 1];
        return sums;
    }
    int upper_bound(vector<int>& sums, int left, int right, int target) {
        int l = left, r = right;
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (sums[m] <= target) l = m + 1;
            else r = m;
        }
        return sums[r] > target ? r : -1;
    }
};

int main() {
    Solution s;
    vector<int> ss{2};
    cout<<s.minSubArrayLen(2,ss)<<endl;
    return 0;
}

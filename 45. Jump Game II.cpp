class Solution {
public:
    int jump(vector<int>& nums) {
      int start=0,end=0,step=0;
      while(end<nums.size()-1){
        step++;
        int father=0;
        for(int i=start;i<=end;i++){
          if(father<i+nums[i]) father=i+nums[i];
        }
        start++;
        end=father;
      }
      return step;
    }
};


class Solution {
public:
    int jump(vector<int>& nums) {
      int n=nums.size();
        if(n <= 1) return 0;
        int *dp = new int[n + 1];
        for(int i=1;i<n;i++)
            dp[i] = INT_MAX;

        dp[0] = 0;
        for(int i = 1; i < n;i++)
        {
            for(int j = 0;j < i;j++)
                if(A[j] + j >= i)
                {
                    if(dp[j] + 1 < dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        break;
                    }
                }
        }

        return dp[n - 1];
    }
};

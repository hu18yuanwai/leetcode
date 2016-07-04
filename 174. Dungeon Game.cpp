class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
      int m=dungeon.size();
      int n=dungeon[0].size();
      vector<vector<int>>dp;
      for(int i=0;i<m;i++) dp.push_back(vector<int>(n,0));
      dp[m-1][n-1]=max(1,1-dungeon[m-1][n-1]);
      for(int i=m-2;i>=0;i--){
        dp[i][n-1]=max(1,dp[i+1][n-1]-dungeon[i][n-1]);
      }

      for(int i=n-2;i>=0;i--){
        dp[m-1][i]=max(1,dp[m-1][i+1]-dungeon[m-1][i]);
      }

      for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
          dp[i][j]=max(1,min(dp[i][j+1],dp[i+1][j])-dungeon[i][j]);
        }
      }
      return dp[0][0];
    }
};

//节约空间

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
      int m=dungeon.size();
      int n=dungeon[0].size();
      vector<int>dp(m,0);
      dp[m-1]=max(1,1-dungeon[m-1][n-1]);
      for(int i=m-2;i>=0;i--){
        dp[i]=max(1,dp[i+1]-dungeon[i][n-1]);
      }

      for(int i=n-2;i>=0;i--){
        dp[m-1]=max(1,dp[m-1]-dungeon[m-1][i]);
        for(int j=m-2;j>=0;j--){
          dp[j]=max(1,min(dp[j+1],dp[j])-dungeon[j][i]);
        }
      }
      return dp[0];
    }
};

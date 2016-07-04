//空间mn
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
      if(grid.size()==0) return 0;
      if( grid[0].size()==0) return 0;
      vector<vector<int>>f;
      for(int i=0;i<grid.size();i++) f.push_back(vector<int>(grid[0].size(),0));
      for(int i=0;i<grid[0].size();i++){
        if(i==0) f[0][i]=grid[0][i];
        else f[0][i]=f[0][i-1]+grid[0][i];
      }

      for(int i=0;i<grid.size();i++){
        if(i==0) continue;
        else f[i][0]=f[i-1][0]+grid[i][0];
      }

      for(int i=1;i<grid.size();i++){
        for(int j=1;j<grid[0].size();j++){
          f[i][j]=min(f[i-1][j],f[i][j-1])+grid[i][j];
        }
      }

      return f[grid.size()-1][grid[0].size()-1];
    }
};


//空间n
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
      int m=grid.size();
      int n=grid[0].size();
      vector<int>pre(n,0);
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(i==0){
            if(j==0)
              pre[0]=grid[i][j];
            else
              pre[j]=pre[j-1]+grid[i][j];
        }

        else{
          if(j==0) pre[j]=pre[0]+grid[i][j];
          else pre[j]=min(pre[j-1],pre[j])+grid[i][j];
        }
      }
    }
    return pre[n-1];
  }
};


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> cur(m, grid[0][0]);
        for (int i = 1; i < m; i++)
            cur[i] = cur[i - 1] + grid[i][0];
        for (int j = 1; j < n; j++) {
            cur[0] += grid[0][j];
            for (int i = 1; i < m; i++)
                cur[i] = min(cur[i - 1], cur[i]) + grid[i][j];
        }
        return cur[m - 1];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>f;
        for(int i=0;i<m;i++) f.push_back(vector<int>(n,0));
        for(int i=0;i<n;i++) f[0][i]=1;
        for(int i=0;i<m;i++) f[i][0]=1;
        for(int i=1;i<m;i++){
        	for(int j=1;j<n;j++){
        		f[i][j]=f[i-1][j]+f[i][j-1];
        	}
        }
        return f[m-1][n-1];
    }
};

//节约空间
class Solution {
public:
    int uniquePaths(int m, int n) {
      vector<int>cur(m,1);
      for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
          cur[j]=cur[j-1]+cur[j];
        }
      }
      return cur[m-1];
    }
};

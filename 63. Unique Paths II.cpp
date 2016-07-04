class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    	int m=obstacleGrid.size(),n=obstacleGrid[0].size();

        vector<vector<int>>f;
        for(int i=0;i<m;i++) f.push_back(vector<int>(n,0));

        for(int i=0;i<n;i++) {
        	if(obstacleGrid[0][i]==1)
        		f[0][i]=0;
        	else{
        		if(i!=0) f[0][i]=f[0][i-1];
        		else f[0][i]=1;
        	}
        }
        
        for(int i=0;i<m;i++){
         if(obstacleGrid[i][0]==1)
         	f[i][0]=0;
         else{
         	if(i!=0) f[i][0]=f[i-1][0];
         	else f[i][0]=1;
         }
     	}

        for(int i=1;i<m;i++){
        	for(int j=1;j<n;j++){
        		if(obstacleGrid[i][j]) f[i][j]=0;
        		else f[i][j]=f[i-1][j]+f[i][j-1];
        	}
        }
        return f[m-1][n-1];
    }
};
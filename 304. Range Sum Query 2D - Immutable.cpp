class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        for(int i=0;i<matrix.size();i++){
        	vector<int>temp(matrix[0].size(),0);
        	result.push_back(temp);
        }
        int sum=0;
        if(matrix.size()){
        	for(int i=0;i<matrix[0].size();i++){
        		sum+=matrix[0][i];
        		result[0][i]=sum;
        	}
        	sum=0;
        	for(int i=0;i<matrix.size();i++){
        		sum+=matrix[i][0];
        		result[i][0]=sum;
        	}

  			for(int i=1;i<matrix.size();i++){
  				for(int j=1;j<matrix[0].size();j++){
  					result[i][j]=result[i-1][j]+result[i][j-1]-result[i-1][j-1]+matrix[i][j];
  				}
  			}
  		}
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
    	if(result.size()==0) return 0;
    	int width=result[0].size();
    	int height=result.size();
    	if(row1<0 || row1>=height || row2<0 || row2>=height || col1<0 ||col1>=width || col2<0 || col2>=width)
    		return 0;
        if(row1==0){
        	if(col1==0)
        		return result[row2][col2];
        	else
        		return result[row2][col2]-result[row2][col1-1];
        }
        else{
        	if(col1==0)
        		return result[row2][col2]-result[row1-1][col2];
        	else
        		return result[row2][col2]-(result[row2][col1-1]+result[row1-1][col2]-result[row1-1][col1-1]);
        }
    }
 private:
 	vector<vector<int>>result;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
class Solution {
public:
  void mirror_image(vector<vector<int>>& matrix){
    int n=matrix.size();
    for(int i=0;i<n/2;i++){
      for(int j=0;j<n;j++){
        int temp=matrix[i][j];
        matrix[i][j]=matrix[n-1-i][j];
        matrix[n-1-i][j]=temp;
      }
    }
  }

  void fold_image(vector<vector<int>>& matrix){
    int n=matrix.size();
    for(int i=0;i<n;i++){
      for(int j=0;j<i;j++){
        int temp=matrix[i][j];
        matrix[i][j]=matrix[j][i];
        matrix[j][i]=temp;
      }
    }
  }

  void rotate(vector<vector<int>>& matrix) {
    mirror_image(matrix);
    fold_image(matrix);
  }
};

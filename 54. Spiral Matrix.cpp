class Solution {
public:
  void printCircle(vector<vector<int>>& matrix, vector<int>& ret,int start){
    int endX=matrix.size()-1-start;
    int endY=matrix[0].size()-1-start;

    for(int i=start;i<=endY;i++)  ret.push_back(matrix[start][i]);

    if(start<endX){
      for(int i=start+1;i<=endX;i++) ret.push_back(matrix[i][endY]);
    }
    if(start<endY && start<endX){
      for(int i=endY-1;i>=start;i--) ret.push_back(matrix[endX][i]);
    }
    if(start<endY && start<endX-1){
      for(int i=endX-1;i>=start+1;i--) ret.push_back(matrix[i][start]);
    }
  }

  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ret;
    if(matrix.size()==0) return ret;
    int start=0;
    while(start*2<matrix.size() && start*2<matrix[0].size()){
      printCircle(matrix,ret,start);
      ++start;
    }
    return ret;
  }
};

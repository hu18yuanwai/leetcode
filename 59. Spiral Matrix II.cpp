class Solution {
public:
  void getMatrix(vector<vector<int>> &ret,int start,int n,int &startN){
  	int endX=n-start-1;
  	int endY=n-start-1;
  	for(int i=start;i<=endY;i++){
  		ret[start][i]=startN;
  		startN++;
  	}
  	for(int i=start+1;i<=endX;i++){
  		ret[i][endY]=startN;
  		startN++;
  	}
  	for(int i=endY-1;i>=start;i--){
  		ret[endX][i]=startN;
  		startN++;
  	}
  	for(int i=endX-1;i>=start+1;i--){
  		ret[i][start]=startN;
  		startN++;
  	}
  }

  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ret;
    for(int i=0;i<n;i++) ret.push_back(vector<int>(n,0));
    int start=0,startN=1;
	while(start*2<n){
		getMatrix(ret,start,n,startN);
		start++;
	}
	return ret;
  }
};

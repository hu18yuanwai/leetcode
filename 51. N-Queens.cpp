class Solution {
public:
  bool isLegal(vector<string> &cur,int rowN,int i){
    for(int j=0;j<cur.size();j++){
      if(cur[rowN][j]=='Q' && j!=i) return false;
      if(cur[j][i]=='Q' && j!=rowN) return false;
    }
    int r=rowN-1,c=i-1;
    while(r>=0 && c>=0){
      if(cur[r][c]=='Q') return false;
      r--;
      c--;
    }

    r=rowN-1,c=i+1;
    while(r>=0 && c<cur.size()){
      if(cur[r][c]=='Q') return false;
      r--;
      c++;
    }

    r=rowN+1,c=i-1;
    while(r<cur.size() && c>=0){
      if(cur[r][c]=='Q') return false;
      r++;
      c--;
    }

    r=rowN+1,c=i+1;
    while(r<cur.size() && c<cur.size()){
      if(cur[r][c]=='Q') return false;
      r++;
      c++;
    }

    return true;
  }

  void backTrack(vector<vector<string>> &ret,vector<string> &cur,int n,int rowN){
    if(rowN>=n) ret.push_back(cur);
    else{
      for(int i=0;i<n;i++){
        cur[rowN][i]='Q';
        if(isLegal(cur,rowN,i))
          backTrack(ret,cur,n,rowN+1);
        cur[rowN][i]='.';
      }
    }
  }

  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ret;
    string row(n,'.');
    vector<string> cur(n,row);
    backTrack(ret,cur,n,0);
    return ret;
    }
};

//解法2，存储方式改变，代码更加简洁
class Solution {
public:
  bool isLegal(vector<int>&cur,int N){
    for(int i=0;i<N;i++) if(cur[i]==cur[N]||abs(N-i)==abs(cur[N]-cur[i])) return false;
    return true;
  }
  void backTrack(vector<vector<string>>& ret,vector<int>&cur,int n,int N){
    if(N>=n){
      string row(n,'.');
      vector<string> curR(n,row);
      for(int i=0;i<n;i++){
        curR[i][cur[i]]='Q';
      }
      ret.push_back(curR);
    }
    else{
      for(int i=0;i<n;i++){
        cur[N]=i;
        if(isLegal(cur,N)) backTrack(ret,cur,n,N+1);
      }
    }
  }

  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ret;
    vector<int> cur(n,-1);
    backTrack(ret,cur,n,0);
    return ret;
    }
};

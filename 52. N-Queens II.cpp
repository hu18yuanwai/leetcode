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

  void backTrack(vector<int> &ret,vector<string> &cur,int n,int rowN){
    if(rowN>=n) ret[0]++;
    else{
      for(int i=0;i<n;i++){
        cur[rowN][i]='Q';
        if(isLegal(cur,rowN,i))
          backTrack(ret,cur,n,rowN+1);
        cur[rowN][i]='.';
      }
    }
  }

  int totalNQueens(int n) {
    string row(n,'.');
    vector<int>total(1);
    vector<string> cur(n,row);
    backTrack(total,cur,n,0);
    return total[0];
  }
};


//解法2


class Solution {
public:
  bool isLegal(vector<int>&cur,int N){
    for(int i=0;i<N;i++) if(cur[i]==cur[N]||abs(N-i)==abs(cur[N]-cur[i])) return false;
    return true;
  }
  void backTrack(int &ret,int n,vector<int>&cur,int N){
    if(N>=n) ret++;
    else{
      for(int i=0;i<n;i++){
        cur[N]=i;
        if(isLegal(cur,N)) backTrack(ret,n,cur,N+1);
      }
    }
  }

  int totalNQueens(int n) {
    int ret=0;
    vector<int>cur(n,-1);
    backTrack(ret,n,cur,0);
    return ret;    
  }
};
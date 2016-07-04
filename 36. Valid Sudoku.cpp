bool checkRows(vector< vector<char> >& board){
  int len=board.size();
  for(int i=0;i<len;i++){
    vector<int> hash(9,0);
    for(int j=0;j<board[i].size();j++){
      if(board[i][j]!='.'){
        if(hash[board[i][j]-'0'-1]) return false;
        else hash[board[i][j]-'0'-1]=1;
      }
    }
  }
  return true;
}

bool checkCol(vector< vector<char> >& board){
  int len=board[0].size();
  for(int i=0;i<len;i++){
    vector<int> hash(9,0);
    for(int j=0;j<board.size();j++){
      if(board[j][i]!='.'){
        if(hash[board[j][i]-'0'-1]) return false;
        else hash[board[j][i]-'0'-1]=1;
      }
    }
  }
  return true;
}

bool checkBox(vector< vector<char> >& board){
  int de[9][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
  for(int i=1;i<board[0].size();i=i+3){
    for(int j=1;j<board.size();j=j+3){
      vector<int> hash(9,0);
      for(int k=0;k<9;k++){
        if(board[j+de[k][0]][i+de[k][1]]!='.'){
          if(hash[board[j+de[k][0]][i+de[k][1]]-'0'-1]) return false;
          else hash[board[j+de[k][0]][i+de[k][1]]-'0'-1]=1;
        }
      }
    }
  }
  return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
  if(checkRows(board) && checkCol(board) && checkBox(board)) return true;
  return false;
}

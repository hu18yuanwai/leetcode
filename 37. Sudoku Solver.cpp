class Solution {
public:
bool checkRows(vector< vector<char> >& board,int x,int y){
  vector<int>hash(9,0);
  for(int i=0;i<board.size();i++){
    if(board[i][y]!='.'){
      if(hash[ board[i][y]-'0'-1 ]==1) return false;
      else hash[ board[i][y]-'0'-1 ]=1;
    }
  }
  return true;
}

bool checkCol(vector< vector<char> >& board,int x,int y){
  vector<int>hash(9,0);
  for(int i=0;i<board[0].size();i++){
    if(board[x][i]!='.'){
      if(hash[ board[x][i]-'0'-1 ]==1) return false;
      else hash[ board[x][i]-'0'-1 ]=1;
    }
  }
  return true;
}

bool checkBox(vector< vector<char> >& board,int x,int y){
  vector<int>hash(9,0);
  x=x-x%3;
  y=y-y%3;
  int de[9][2]={{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
  for(int i=0;i<9;i++){
    if(board[x+de[i][0]][y+de[i][1]]!='.'){
      if(hash[board[x+de[i][0]][y+de[i][1]]-'0'-1]==1) return false;
      else hash[board[x+de[i][0]][y+de[i][1]]-'0'-1]=1;
    }
  }
  return true;
}

bool isValidSudoku(vector<vector<char>>& board,int x, int y) {
  if(checkRows(board,x,y) && checkCol(board,x,y) && checkBox(board,x,y)) return true;
  return false;
}

void backStrack(vector<vector<char>>& temp,int i,int j,vector<vector<char>>& board){
  if(i>=temp.size()) {
    for(int k=0;k<board.size();k++){
      for(int w=0;w<board[0].size();w++){
        board[k][w]=temp[k][w];
      }
    }
    return;
  }
  if(temp[i][j]!='.'){
    backStrack(temp,i+(j+1)/temp[0].size(),(j+1)%temp[0].size(),board);
  }
  else{
    for(int k=1;k<=9;k++){
      temp[i][j]='0'+k;
      if(isValidSudoku(temp,i,j)){
        backStrack(temp,i+(j+1)/temp[0].size(),(j+1)%temp[0].size(),board);
      }
    }
    temp[i][j]='.';
  }
}

void solveSudoku(vector<vector<char>>& board) {
  vector<vector<char>> temp(board);
  backStrack(temp,0,0,board);
}
};

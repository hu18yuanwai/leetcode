class Solution {
public:

    void search(vector<vector<char>>& board, string word,int i, int j,bool &ret){
        if(ret) return;

        if(word.size()==0){
            ret = true;
            return;
        }
        for(int k=0;k<4;k++){
            if(i+direction[k][0]>=0 && i+direction[k][0]<board.size() && j+direction[k][1]<board[0].size() && j+direction[k][1]>=0){
                if(board[i+direction[k][0]][j+direction[k][1]] == word[0]){
                    board[i+direction[k][0]][j+direction[k][1]]='#';
                    search(board,word.substr(1),i+direction[k][0],j+direction[k][1],ret);
                    board[i+direction[k][0]][j+direction[k][1]]=word[0];
                }
            }
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()==0) return true;
        int row = board.size(), col = board[0].size();
        if(row==0 || col==0) return false;


        bool ret;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0]){
                    char temp=word[0];
                    board[i][j]='#';
                    search(board,word.substr(1),i,j,f,ret);
                    board[i][j]=temp;
                    if(ret) return ret;
                }
            }
        }
        return false;
    }

private:
    int direction[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
};


class Solution {
public:

    void search(vector<vector<char>>& board, string word,int i, int j, vector< vector<bool> >&f,bool &ret){
        if(ret) return;

        if(word.size()==0){
            ret = true;
            return;
        }

        for(int k=0;k<4;k++){
            if(i+direction[k][0]>=0 && i+direction[k][0]<board.size() && j+direction[k][1]<board[0].size() && j+direction[k][1]>=0){
                if(f[i+direction[k][0]][j+direction[k][1]]==false && board[i+direction[k][0]][j+direction[k][1]] == word[0]){
                    f[i+direction[k][0]][j+direction[k][1]]=true;
                    search(board,word.substr(1),i+direction[k][0],j+direction[k][1],f,ret);
                    f[i+direction[k][0]][j+direction[k][1]]=false;
                }
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()==0) return true;
        int row = board.size(), col = board[0].size();
        if(row==0 || col==0) return false;
        vector< vector<bool> >f(row, vector<bool>(col,0));

        bool ret;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0]){
                    f[i][j]=true;
                    search(board,word.substr(1),i,j,f,ret);
                    f[i][j]=false;
                    if(ret) return ret;
                }
            }
        }
        return false;
    }

private:
    int direction[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
};

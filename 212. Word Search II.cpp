class Solution {
public:
    class TrieNode {
    public:
        char content;
        bool isEnd;
        int count;
        list<TrieNode*> childList;
        // Initialize your data structure here.
        TrieNode(char c) {
            content=c;
            isEnd=false;
            count=0;
        }

        TrieNode(){
            content=0;
            isEnd=false;
            count=0;
        }

        TrieNode* subNode(char c){
            if(childList.size()==0) return NULL;
            for(auto i = childList.begin();i!=childList.end();i++){
                if((*i)->content==c) return *i;
            }
            return NULL;
        }
    };

    class Trie {
    public:
        Trie() {
            root = new TrieNode();
        }

        // Inserts a word into the trie.
        void insert(string word) {
            if(search(word)==true) return;

            TrieNode *current =root;
            for(int i=0;i<word.size();i++){
                TrieNode* child  = current->subNode(word[i]);
                if(child!=NULL){
                    current = child;
                }else{
                    current->childList.push_back(new TrieNode(word[i]));
                    current=current->subNode(word[i]);
                }
                current->count++;
            }
            current->isEnd=true;
        }

        // Returns if the word is in the trie.
        bool search(string word) {
            TrieNode* current = root;
            for(int i=0;i<word.size();i++){
                if(current->subNode(word[i])==NULL)
                    return false;
                else
                    current = current->subNode(word[i]);
            }

            if(current->isEnd==true) return true;
            return false;
        }

        // Returns if there is any word in the trie
        // that starts with the given prefix.
        bool startsWith(string prefix) {
            TrieNode* current = root;
            for(int i=0;i<prefix.size();i++){
                if(current->subNode(prefix[i])==NULL) return false;
                else current = current->subNode(prefix[i]);
            }
            return true;
        }

        void deleteNode(TrieNode* p){
            if(p==NULL) return;
            for(auto i=p->childList.begin();i!=p->childList.end();i++){
                deleteNode(*i);
            }
            delete p;
        }

        ~Trie(){
            deleteNode(root);
        }
    private:
        TrieNode* root;
    };

    void dfs(set<string>& ret_set,vector<vector<char>>& board,string word, int x, int y, Trie& trie){
        if(x<0 || x >= board.size() || y<0 || y>= board[0].size() || board[x][y]=='*') return;
        word+=board[x][y];
        if(trie.startsWith(word)==false) return;
        if(trie.search(word)) ret_set.insert(word);
        char temp =board[x][y];
        board[x][y]='*';
        for(int k=0;k<4;k++){
            dfs(ret_set,board,word,x+d[k][0],y+d[k][1],trie);
        }
        board[x][y]=temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string>ret;
        if(board.size()==0 || board[0].size()==0 || words.size()==0) return ret;
        set<string> ret_set;
        Trie trie;
        for(int i=0;i<words.size();i++){
            trie.insert(words[i]);
        }

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                dfs(ret_set,board,"",i,j,trie);
            }
        }

        for(auto i = ret_set.begin();i!=ret_set.end();i++)
            ret.push_back(*i);
        return ret;
    }
private:
    int d[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
};

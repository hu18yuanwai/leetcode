#include <iostream>
#include <string>
#include <cstring>
using namespace std;
 
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode(char ch){
        c=ch;
        for(int i=0;i<27;i++)
            next[i]=NULL;
    }
    TrieNode() {
        c=' ';
        for(int i=0;i<27;i++)
            next[i]=NULL;
    }
    char c;
    TrieNode *next[27];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *cur=root;
        for(int i=0;i<=word.size();i++){
            TrieNode * find=find_node(cur,word[i]);
            if(find==NULL){
                int j=0;
                while(j<27 && cur->next[j]!=NULL) j++;
                cur->next[j]=new TrieNode(word[i]);
                cur=cur->next[j];
            }
            else{
                cur=find;
            }
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *cur=root;
        for(int i=0;i<=word.size();i++){
            TrieNode * find=find_node(cur,word[i]);
            if(find==NULL) return false;
            cur=find;
        }
        return true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *cur=root;
        for(int i=0;i<prefix.size();i++){
            TrieNode * find=find_node(cur,prefix[i]);
            if(find==NULL) return false;
            cur=find;
        }
        return true;
    }

private:
    TrieNode* root;
    TrieNode* find_node(TrieNode * node, char c){
        for(int i=0;i<27;i++){
            if(node->next[i]!=NULL && node->next[i]->c==c)
                return node->next[i];
        }
        return NULL;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main(){
    Trie trie;
    trie.insert("abc");
    cout<<trie.search("abc")<<endl;
    cout<<trie.search("ab")<<endl;
    trie.insert("ab");
    cout<<trie.search("ab")<<endl;
    trie.insert("ab");
    cout<<trie.search("ab")<<endl;  
    string s="string";
    return 0;
}



class TrieNode {
public:
    char var;
    bool isWord;
    TrieNode* children[26];
    // Initialize your data structure here.
    TrieNode() {
        var = 0;
        isWord = false;
        memset(children, 0x0, sizeof(TreeNode*)*26);

    }
    TrieNode(char c){
        var = c;
        isWord = false;
        memset(children, 0x0, sizeof(TreeNode*)*26);
    }
};


class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* pNode = root;
        if (word.length() <= 0)
        {
            return;
        }
        for (int i= 0; i<word.length(); i++)
        {
            char c= word[i];
            if (pNode->children[c-'a'] == 0)
            {
                TrieNode *pNew = new TrieNode(c);
                pNode->children[c-'a'] = pNew;
            }
            pNode = pNode->children[c-'a'];
        }
        pNode->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *pNode = root;
        if (word.length() <= 0)
            return true;
        for (int i =0; i<word.length(); i++)
        {
            char c = word[i];
            pNode = pNode->children[c-'a'];
            if (pNode == NULL)
                return false;
        }
        return pNode->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *pNode = root;
        if (prefix.length()<=0)
            return true;
        for (int i=0; i<prefix.length(); i++)
        {
            char c = prefix[i];
            pNode = pNode->children[c-'a'];
            if (pNode == NULL)
                return false;
        }
        return true;
    }
    void freeTrieNode(TrieNode* pNode){
        if (pNode == NULL)
            return;
        for (int i=0; i<26;i++)
        {
            TrieNode* pChild = pNode->children[i];
            if (pChild != NULL)
            {
                freeTrieNode(pChild);
            }
        }
        free(pNode);
    }
    ~Trie(){
        freeTrieNode(root);
    }
private:
    TrieNode* root;
};

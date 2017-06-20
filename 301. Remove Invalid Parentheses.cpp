#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    void DFS(string s, char ch, int last)
    {
        for(int i = 0, cnt = 0; i < s.size(); i++)
        {
            if(s[i]=='('||s[i]==')') s[i]==ch?cnt++:cnt--;
            if(cnt <= 0) continue;
            for(int j = last; j <= i; j++)
            {
                if(s[j] == ch && (j ==last || s[j-1]!= ch))
                    DFS(s.substr(0, j)+s.substr(j+1), ch, j);
            }
            return;
        }
        reverse(s.begin(), s.end());
        if(ch == ')') return DFS(s, '(', 0);
        ans.push_back(s);
    }
    
    vector<string> removeInvalidParentheses(string s) {
        ans.resize(0);
        DFS(s, ')', 0);
        return ans;
    }
private:
    vector<string> ans;
};

class Solution2 {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ret;
        queue<string> myq;
        unordered_map<string,int> mym;
        myq.push(s);
        mym[s]++;
        bool find = false;
        while(!myq.empty()){
            s = myq.front();
            myq.pop();
            if(isvaid(s)){
                ret.push_back(s);
                find = true;
            }
            if(find) continue;

            for(int i=0;i<s.size();i++){
                if(s[i]!='(' && s[i]!=')') continue;
                string t = s.substr(0,i) + s.substr(i+1);
                if(mym.find(t)== mym.end()){
                    myq.push(t);
                    ++mym[t];
                }
            }
        }
        return ret;
    }
private:
    bool isvaid(string s){
        int cnt =0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') cnt++;
            if(s[i]==')' && cnt--==0) return false;
        }
        return cnt==0;
    }
};

int main(){
    string s;
    cin>>s;
    Solution sol;
    vector<string> ret = sol.removeInvalidParentheses(s);
    for(auto i= ret.begin(); i!=ret.end();i++){
        cout<<*i<<endl;
    }
    return 0;
}
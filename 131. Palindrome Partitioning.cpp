class Solution {
public:
    void backstrack(string s,vector<vector<string>>& ret, vector<string> &temp){
        if(s.size()==0){
            ret.push_back(temp);
            return;
        }

        for(int i=1;i<=s.size();i++){
            string str = s.substr(0,i);
            string temp_s = s;
            if(ispalindrome(str)){
                temp.push_back(str);
                s= s.substr(i);
                backstrack(s,ret,temp);
                s= temp_s;
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector< vector<string> > ret;
        vector<string> temp;
        backstrack(s,ret,temp);
        return ret;
    }

private:
    bool ispalindrome(string s){
        if(s.size()==0) return true;
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

class Solution {
public:
    bool isvaid(string s){
        int a = stoi(s);
        stringstream stream;
        stream<<a;
        if(stream.str().size() == s.size()) return true;
        return false;
    }

    void backstrak(string s, int depth,vector<string>&ret, string temp){
        if(depth>=3){
            if(s.size()<4 && stoi(s)<=255 && isvaid(s)){
                temp+='.'+s;
                ret.push_back(temp);
            }
            return;
        }
        for(int i=0;i<3 && i<s.size();i++){
            string subStr = s.substr(0,i+1);
            if(stoi(subStr)<=255){
                string temp_ =temp;
                if(depth>0) temp+='.';
                temp+=subStr;
                if(s.substr(i+1)!="" && isvaid(subStr))
                    backstrak(s.substr(i+1),depth+1,ret,temp);
                temp = temp_;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>ret;
        string temp;
        backstrak(s,0,ret,temp);
        return ret;
    }
};

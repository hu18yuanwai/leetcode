class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    if(strs.size()==0) return vector<vector<string>>();
    sort(strs.begin(),strs.end());
    map <string, vector<string> > mv;
    vector<vector<string>> ret;

    for(int i=0;i<strs.size();i++){
      string str=strs[i];
      sort(str.begin(),str.end());
      mv[str].push_back(strs[i]);
    }

    for(map <string, vector<string> >::iterator iter=mv.begin();iter!=mv.end();iter++)
      ret.push_back(iter->second);
    return ret;
  }
};

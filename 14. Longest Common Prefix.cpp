bool find(vector<string>& strs, int j){
  if(strs.size()==0) return false;
  char s=strs[0][j];
  for(int i=1;i<strs.size();i++)
    if(strs[i][j]!=s) return false;
  return true;
}

string longestCommonPrefix(vector<string>& strs) {
      string restring="";
      int minlen=INT_MAX;
      for(int i=0;i<strs.size();i++)
        if(minlen>strs[i].size()) minlen=strs[i].size();
      for(int i=0;i<minlen && find(strs,i);i++){
        char s=strs[0][i];
        restring+=s;
      }
      return restring;
}

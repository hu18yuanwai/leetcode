bool com(string s1,string s2){
  for(int i=0;i<s1.size();i++){
    if(s1[i]!=s2[i]) return false;
  }
  return true;
}

int strStr(string haystack, string needle) {
  int len1=haystack.size(),len2=needle.size();
  if(len1<len2) return -1;
  for(int i=0;i<=len1-len2;i++){
      //cout<<haystack.substr(i,len2)<<" "<<needle<<endl;
      if(com(haystack.substr(i,len2),needle)) return i;
  }
  return -1;
}

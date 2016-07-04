bool isMatch(string s, string p) {
  int lens=s.size(),lenp=p.size();
  if(lenp==0) return lens==0;
  if(lenp==1 || p[1]!='*'){
    if(lens<1 || (p[0]!='.' && p[0]!=s[0]))
      return false;
    return isMatch(s.substr(1,lens),p.substr());
  }
  int i=0;
  while(p[0]==s[0] ||(p[0]=='.' && s[i]!='\0')){
    if(isMatch(s.substr(i,lens-i),p.substr(2,lenp-2))) return true;
    i++;
  }
  return isMatch(s,,substr(i,lens-i),p.substr(2,lenp-2));
}

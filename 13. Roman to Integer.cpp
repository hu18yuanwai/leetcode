int getInt(char c){
switch(c){
  case 'I': return 1;
  case 'V': return 5;
  case 'X': return 10;
  case 'L': return 50;
  case 'C': return 100;
  case 'D': return 500;
  case 'M': return 1000;
  default: return 0;
}
}

int romanToInt(string s) {
if(s.size()==0) return 0;
int reInt=0;
for(int i=s.size()-1;i>=0;i--){
  if(i==s.size()-1) {reInt+=getInt(s[i]);continue;}
  if(getInt(s[i])>=getInt(s[i+1])) reInt+=getInt(s[i]);
  else reInt-=getInt(s[i]);
}
return reInt;
}

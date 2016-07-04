bool isChar(char c){
  if((c>='a'&& c<='z') || (c>='A' && c<='Z'))
    return true;
  return false;
}

int lengthOfLastWord(string s) {
  int len=s.size();
  int count=len-1,re=0;
  while(count>=0 && !isChar(s[count])) count--;
  while(count>=0 && isChar(s[count])) {re++;count--;}
  return re;
}

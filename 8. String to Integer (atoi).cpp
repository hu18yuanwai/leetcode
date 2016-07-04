bool range(long long x){
  if(x<=2147483647&&x>=-2147483648) return true;
  return false;
}

int myAtoi(string s) {
     int len=s.size(),i=0,flag=0;
     long long re=0;
      if(len==0)
          return 0;
      while(s[i]==' ' && i<len) i++;
      if(i<len && (s[i]=='+' || s[i]=='-')){
        if(s[i]=='-') flag=1;
        i++;
      }
      if(i>=len && (s[i]!='.'||s[i]<'0'||s[i]>'9'))
       return 0;
      while(i<len && s[i]=='0') i++;

      for(int j=i;j<len && s[j]!='.' && s[j]<='9' && s[j]>='0';j++){
        re=(s[j]-'0')+re*10;
        if(re>2147483648) re=2147483648;
      }
      if(flag==1){
         if(re>2147483648) return -2147483648;
         return (int)re*(-1);
      }
      if(re>2147483647) return 2147483647;
      return (int)re;
    }

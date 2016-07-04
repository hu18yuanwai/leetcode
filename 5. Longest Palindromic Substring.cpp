//线性算法
string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);

  ret += "#$";
  return ret;
}

string longestPalindrome(string s) {
  string T = preProcess(s);
  int n = T.length();
  int *P = new int[n];
  int C = 0, R = 0;
  for (int i = 1; i < n-1; i++) {
    int i_mirror = 2*C-i; // equals to i' = C - (i-C)

    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;

    // Attempt to expand palindrome centered at i
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
      P[i]++;

    // If palindrome centered at i expand past R,
    // adjust center based on expanded palindrome.
    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
  }

  // Find the maximum element in P.
  int maxLen = 0;
  int centerIndex = 0;
  for (int i = 1; i < n-1; i++) {
    if (P[i] > maxLen) {
      maxLen = P[i];
      centerIndex = i;
    }
  }
  delete[] P;

  return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
}


//解法，中间展开

string isSpan(string s,int pos){
  int len=s.size();
  if(pos<0 && pos>=2*len-2)
    return "";
  int x1,x2;
  if(pos&1){
      x1=(pos-1)>>1,x2=(pos+1)>>1;
    }
  else{
    x1=pos/2-1,x2=pos/2+1;
  }
  while(x1>=0 && x2<len s[x1]==s[x2]){
    x1--;
    x2++;
  }
  return s.substr(x1+1,x2-x1-1);
}

string longestPalindrome(string s) {
  int len=s.size();
  int max=0;
  string re;
  for(int i=0;i<2*len-1;i++){
    string sr=isSpan(s,i);
    if(sr.size()>max){
      max=sr.size();
      re=sr;
    }
  }
  return re;
}




//递归
int max3(int a, int b,int c){
  int max=a;
  if(max<b) max=b;
  if(max<c) max=c;
  return max;
}

string longestPalindrome(string s) {
  if(s.size()==1||s.size()==0)
    return s;
  if(s[0]==s[s.size()-1]){
    int low=0,high=s.size()-1;
    int flag=1;
    while(high>=low){
      if(s[low]!=s[high]){
        flag=0;
        break;
      }
      low++;
      high--;
    }
    if(flag)
      return s;
  }
  string subStr1=s.substr(1,s.size()-2);
  string subStr2=s.substr(0,s.size()-1);
  string subStr3=s.substr(1,s.size()-1);
  string re1=longestPalindrome(subStr1);
  string re2=longestPalindrome(subStr2);
  string re3=longestPalindrome(subStr3);
  int lenMax=max3(re1.size(),re2.size(),re3.size());
  if(re1.size()==lenMax)
    return re1;
  if(re2.size()==lenMax)
    return re2;
  if(re3.size()==lenMax)
    return re3;
}


//动态规划
string longestPalindrome(string s) {
  int len=s.size(),x=0,y=0;
  bool find[len][len];
  for(int i=0;i<len;i++)
    for(int j=0;j<len;j++)
      if(i>=j) find[i][j]=true;
      else find[i][j]=false;
  for(int j=1;j<len;j++){
     for(int i=0;i<j;i++){
       if(s[i]==s[j]){
         find[i][j]=find[i+1][j-1];
         if(find[i][j]==true && (j-i>y-x)){
           x=i;
           y=j;
         }
       }
       else find[i][j]=false;
     }
  }
  return s.substr(x,y-x+1);
}

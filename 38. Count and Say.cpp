class Solution {
public:
  string reverse(string re){
	int i=0,j=re.size()-1;
	while(i<j){
		int temp=re[i];
		re[i]=re[j];
		re[j]=temp;
		i++;
		j--;
	}
	return re;
}

string intToString(int a){
    string re="";
    while(a){
      re+=(a%10)+'0';
      a=a/10;
    }
    re=reverse(re);
    return re;
  }

  string nextStr(string str){
      string re="";
      int j=0;
      while(j<str.size()){
        int count=0,i=j;
        while(str[i]==str[j] &&j<str.size()){
          count++;
          j++;
        }
        re=re+intToString(count)+str[i];
      }
      return re;
  }
  string nextStr2(string str1){
      string re="";
      int j=0;
      stringstream ss;
      while(j<str1.size()){
        int count=0,i=j;
        while(str1[i]==str1[j] &&j<str1.size()){
          count++;
          j++;
        }
        ss<<count<<str1[i];
      }
      return ss.str();
  }
  string countAndSay(int n) {
    if(n<=0) return "";
    string re="1";
    for(int i=1;i<n;i++){
      re=nextStr(re);
    }
    return re;
  }
};

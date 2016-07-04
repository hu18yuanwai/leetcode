class Solution {
public:
  void reverse(string &str){
    int i=0,j=str.size()-1;
    while(i<j){
      char tem=str[i];
      str[i]=str[j];
      str[j]=tem;
      i++;
      j--;
    }
  }

  string addString(string str1,string str2){
    if(str1=="") return str2;
    if(str2=="") return str1;
    string ret="";
    int index1=str1.size()-1,index2=str2.size()-1,cnt=0;
    while(index1>=0 && index2>=0){
      int sum=(str1[index1]-'0')+(str2[index2]-'0')+cnt;
      ret+=(sum%10)+'0';
      cnt=sum/10;
      index1--;
      index2--;
    }
    while(index1>=0){
      int sum=(str1[index1]-'0')+cnt;
      cnt=sum/10;
      ret+=(sum%10)+'0';
      index1--;
    }
    while(index2>=0){
      int sum=(str2[index2]-'0')+cnt;
      cnt=sum/10;
      ret+=(sum%10)+'0';
      index2--;
    }
    if(cnt!=0) ret+=cnt+'0';
    reverse(ret);
    return ret;
  }

  string StringMultiChar(string longStr,char c,int ReIndex){
    string ret="";
    int cnt=0;
    for(int i=longStr.size()-1;i>=0;i--){
      int mu=(c-'0')*(longStr[i]-'0')+cnt;
      ret+=(mu%10)+'0';
      cnt=mu/10;
    }
    if(cnt!=0) ret+=(cnt+'0');
    reverse(ret);
    while(ReIndex--) ret=ret+='0';
    return ret;
  }

  string multi(string longStr,string shortStr){
    string ret="";
    if(longStr=="" || shortStr=="") return ret;
    for(int i=shortStr.size()-1;i>=0;i--){
      string temp=StringMultiChar(longStr,shortStr[i],shortStr.size()-1-i);
      ret=addString(ret,temp);
    }
    return ret;
  }

  string multiply(string num1, string num2) {
    int lenNum1=num1.size();
    int lenNum2=num2.size();
    if(num1=="0" ||num2=="0") return "0";
    if(lenNum1>=lenNum2) return multi(num1,num2);
    else return multi(num2,num1);
  }
};


//方法二 更加简洁
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size(), len = len1 + len2;
        string str(len, '0');
        for (int i = len1 - 1; i >= 0; i--)
        {
            int a = num1[i] - '0';
            for (int j = len2 - 1, k = len2 + i; j >= 0; j--, k--)
            {
                int b = num2[j] - '0';
                int c = str[k] - '0';
                int t = b * a + c;
                str[k] = t % 10 + '0';
                int d = (str[k-1] - '0') + t / 10;
                if (d >= 10)  //开始这里没有等号，检查了很久才发现，细心啊细心
                    str[k-2] = str[k-2] - '0' + d / 10 + '0';
                str[k-1] = d % 10 + '0';
            }
        }
        int x = 0;
        while (str[x] == '0')
            x++;
        if (str.substr(x, len - x) == "")
            return "0";
        return str.substr(x, len - x);

    }
};

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string convert(string s, int numRows) {
  int len=s.size();
  if(numRows==1) return s;
  char re[len];
  int count=0;
  for(int i=1;i<=numRows;i++){
    int iter=i-1;
    int cal1=(numRows-i)*2;
    int cal2=(i-1)*2;
    int count_iter=0;
    while(iter<len){
      count_iter++;
      re[count]=s[iter];
      if(count_iter&1){
        iter=iter+cal1;
        if(cal1!=0) count++;
      }
      else{
        iter=iter+cal2;
        if(cal2!=0) count++;
      }
        }
    }
    re[count]='\0';
    return re;
}


int main(){
  while(1){
    int len;
    cin>>len;
    if(len==0){
      break;
    }
    string s;
    cin>>s;
    cout<<convert(s,len)<<endl;
  }
  return 0;
}

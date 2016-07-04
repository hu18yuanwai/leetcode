class Solution {
public:
  int mypow(int a,int b){
    int ret=1;
    for(int i=0;i<b;i++) ret*=a;
    return ret;
  }
    vector<int> grayCode(int n) {
        vector<int>ret;
        if(n==0){
          ret.push_back(0);
          return ret;
        }
        ret=grayCode(n-1);
        int size=ret.size();
        int sum=mypow(2,n-1);
        for(int i=size-1;i>=0;i--){
          ret.push_back(ret[i]+sum);
        }
        return ret;
    }
};

//错误解法
class Solution {
public:
    bool not_in_ret(vector<int>&ret,int num){
      for(int i=0;i<ret.size();i++){
        if(ret[i]==num) return false;
      }
      return true;
    }

    bool adjcent(int a,int b){
      int x=a^b;
      int countOne=0;
      while(x){
        int w=x%2;
        if(w==1) countOne++;
        x=x>>1;
      }
      if(countOne==1) return true;
      return false;
    }

    void back(vector<int>&ret,const int n){
      if(ret.size()<n){
          int test=ret[ret.size()-1];
          for(int i=1;i<n;i++){
            if(not_in_ret(ret,i) && adjcent(i,test)){
              ret.push_back(i);
              back(ret,n);
              break;
            }
          }
      }
    }

    vector<int> grayCode(int n) {
      vector<int>ret;
      if(n==0) return ret;
      ret.push_back(0);
      if(n==1) return ret;
      int max=1;
      for(int i=1;i<n;i++) max=max*2;
      back(ret,max-1);
      return ret;
    }
};

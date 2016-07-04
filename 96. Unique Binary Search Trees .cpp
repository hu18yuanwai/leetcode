class Solution {
public:
    int numTrees(int n) {
      vector<int>f(n+1,0);
      f[0]=1;
      f[1]=1;
      for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
          f[i]+=f[i-1-j]*f[j];
        }
      }
      return f[n];
    }
};

class Solution {
public:
    int numTrees(int n) {
      if(n==0) return 1;
      long long ret=1;
      for(int i=1;i<=n;i++)
        ret=ret*(2*i-1)*2/(i+1);
      return ret;
    }
};

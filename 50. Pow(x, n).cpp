double myPow(double x, int n) {
  if(n<0) sign=-1;
  double re=1.0;
  while(n){
    if(n&1) re*=x;
    x=x*x;
    n=n>>1;
  }
  return re;
}

class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<0)
		{
			if(n==INT_MIN)
				return 1.0 / (pow(x,INT_MAX)*x);
			else
				return 1.0 / pow(x,-n);
		}
        if(n==0)
            return 1.0;
		double ans = 1.0 ;
		for(;n>0; x *= x, n>>=1)
		{
			if(n&1>0)
				ans *= x;
		}
		return ans;
    }
};

double myPow(double x, int y)
{
    if(y==0) return 1;
    int sign=(y>0?1:-1);
    y=abs(y);
    if (y == 1){
      if(sign==-1) return 1.0/x;
      return x;
    }
    double result = 0;
    double tmp = myPow(x, y/2);
    if(y&1 != 0)
    {
        result = x * tmp * tmp;
        if(sign==-1) result=1.0/result;
    }
    else
    {
        result = tmp * tmp;
        if(sign==-1) result=1.0/result;
    }

    return result;
}

long long int divideLong(long long dividend,long long divisor){
  if(dividend==0) return 0;
  if(divisor==0) return INT_MAX;
  int sign=1;
  if((dividend<0)^(divisor<0)) sign=-1;
  dividend=abs(dividend);
  divisor=abs(divisor);
  if(dividend<divisor) return 0;
  long long ren=divisor;
  long long re=1;
  while((ren<<1)<dividend){
    re=re<<1;
    ren=ren<<1;
  }
  re=re+divideLong(dividend-ren,divisor);
  return re*sign;
}

 int divide(int dividend, int divisor) {
  long long int ret=divideLong(dividend,divisor);
  if(ret<INT_MIN || ret>INT_MAX) return INT_MAX;
  return ret;
}

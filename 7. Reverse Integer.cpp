2,147,483,648
2,147,483,647

int reverse(int x) {
    long long re=0;
    int flag=0;
    long long xlong=x;
    if(xlong<0){
      flag=1;
      xlong=-xlong;
    }
    while(xlong){
      re=re*10+(xlong%10);
      xlong=xlong/10;
    }
    if(flag==0 && re>2147483647) return 0;
    if(flag==1 && re>2147483648) return 0;
    if(flag==0) return (int)re;
    if(flag==1) return (int)re*(-1);
}

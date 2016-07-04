int mySqrt(int x) {
       double xnn=0,xn=x;
       int flag=0;
       while(xn-xnn>=1){
         if(flag)
           xn=xnn;
         else{
           xn=x;
           flag++;
         }
         xnn=0.5*xn+x/(2.0*xn);
         //cout<<xnn<<" "<<xn<<endl;
   }
   return (int)xnn;
   }

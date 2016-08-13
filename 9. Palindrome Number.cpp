int myPow(int n,int t){
  int sum=1;
  for(int i=0;i<t;i++){
    sum*=n;
  }
  return sum;
}

bool isPalindrome(int x) {
      if(x<0)
        return false;
      int len=0,temp=x;
      while(temp){
        temp/=10;
        len++;
  }
  while(len>0){
    if(x/myPow(10,len-1)!=x%10)
      return false;
    x=x%myPow(10,len-1)/10;
    len=len-2;
  }
  return true;
}


class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }

        int originalNumber = x;
        int reversedNumber = 0;
        while (x)
        {
            reversedNumber = (reversedNumber * 10) + (x % 10);
            x /= 10;
        }

        return originalNumber == reversedNumber;
    }
};

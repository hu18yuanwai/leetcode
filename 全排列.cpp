#include <iostream>
using namespace std;

bool IsSwap(char *pszStr, int nBegin, int nEnd)
{
       for (int i = nBegin; i < nEnd; i++)
       if (pszStr[i] == pszStr[nEnd])
             return false;
       return true;
}

void Perm( char *pszStr , int k , int m ) //需要三个参数，k表示当前的数，m表示数的个数
{
      if (k == m)
      {
           static int s_i = 1;
           cout<<” 第 ”<<s_i ++<<” 个排列  ”<<pszStr<<endl;
     }
     else
     {
           for (int i = k; i <= m; i++) //第i个数分别与它后面的数字交换就能得到新的排列
           {
                  Swap(pszStr + k, pszStr + i);
                  Perm(pszStr, k + 1, m);
                  Swap(pszStr + k, pszStr + i);
           }
      }
}


void Perm(char *pszStr, int k, int m)
{
     if (k == m)
     {
          Static int s_i = 1;
          cout<<” 第 ”<<s_i ++<<” 个排列  ”<<pszStr<<endl;
     }
     else
     {
          for (int i = k; i <= m; i++) //第i个数分别与它后面的数字交换就能得到新的排列
          {
                if (IsSwap(pszStr, k, i))   //添加的判断语句，判断是否相等
                {
                      Swap(pszStr + k, pszStr + i);
                      Perm(pszStr, k + 1, m);
                      Swap(pszStr + k, pszStr + i);
                }
           }
      }
}

Foo(const char *str)
{
     Perm( str , 0 , strlen( str ) – 1 );
}

int main(){

}

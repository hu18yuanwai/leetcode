#include <iostream>
#include <cstring>
#include <ctype.h>
#include <stdlib.h>
#include <string>
using namespace std;

char a[100];
char b[100];

void GetPowerSet(int i, char a[])
{
    char x;
    int k;
    int len = strlen(a);
    if(i >= len)
    {
        if(b[0])
            cout << b <<  endl;
        else
            cout << "XX" << endl;  // 表示空集
    }
    else
    {
        x = a[i];
        k = strlen(b);
        b[k] = x;//取 继续向下扩张
        GetPowerSet(i+1, a);
        b[k] = 0;//舍弃 停滞
        GetPowerSet(i+1, a);
    }
}


int main()
{
    while(scanf("%s", a) != EOF)
    {
        printf("%s的幂集是:\n", a);
        printf("------------\n");
        GetPowerSet(0, a);
        printf("------------\n");
    }
}

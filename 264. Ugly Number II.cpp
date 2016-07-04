int min(int a, int b, int c){
        int minNum = a > b ? b : a;
        return minNum > c ? c : minNum;
}
    //求第N个丑数
int nthUglyNumber(int n) {
    int *value=new int[n];
    memset(value,0,sizeof(int)*n);
    int index2=index3=index5=0;
    value[0]=1;
    for(int i=1;i<n;i++){
      int minNum=min(value[index2]*2,value[index3]*3,value[index5]*5);
      value[i]=minNum;
      if(minNum==value[index2]*2) index2++;
      else if(minNum==value[index3]*3) index3++;
      else index5++;
    }
    return value[n-1];
}


int getMin(int a, int b, int c)
 {
     return a<b ?(a<c ? a :c ) :(b<c? b:c);
 }

 int nthUglyNumber(int n) {
    int count = 1;
    int num = 1;
    list<int> l2;
    list<int> l3;
    list<int> l5;

    while(count != n)
    {
        l2.push_back(2*num);
        l3.push_back(3*num);
        l5.push_back(5*num);

        int l2min = l2.front();
        int l3min = l3.front();
        int l5min = l5.front();

        int minNum = getMin(l2min, l3min, l5min);
        if(l2min == minNum) l2.pop_front();
        if(l3min == minNum) l3.pop_front();
        if(l5min == minNum) l5.pop_front();
        num = minNum;
        count++;
    }
}


struct myCop{
  bool operator(int&a , int &b)const{
    return a<b;
  }
};

int nthUglyNumber(int n){
  set<int>se;
  se.insert(1);
  while(--n){
    int a=*se.begin();
    se.erase(a);
    if(a<=INT_MAX/2) se.insert(a*2);
    if(a<=INT_MAX/3) se.insert(a*3);
    if(a<=INT_MAX/5) se.insert(a*5);
  }
  return *se.begin();
}


///多做了工作，set本身就可以排序
int nthUglyNumber(int n) {
  priority_queue<int, vector<int>, greater<int> >que1;
  set<int>set1;
  que1.push(1);
  set1.insert(1);
  int re;int count=2*n-1;
  while(--n){
    re=que1.top();
    que1.pop();
    if(re<=INT_MAX/2 &&count){
      if(set1.find(re*2)==set1.end()){
        que1.push(re*2);
        set1.insert(re*2);
        count--;
      //cout<<"push "<<re*2<<endl;
      }
    }
    if(re<=INT_MAX/3 && count){
      if(set1.find(re*3)==set1.end()){
        que1.push(re*3);
        set1.insert(re*3);
        count--;
        //cout<<"push "<<re*3<<endl;
      }
    }
    if(re<=INT_MAX/5 && count){
      if(set1.find(re*5)==set1.end()){
        que1.push(re*5);
        set1.insert(re*5);
        count--;
        //cout<<"push "<<re*4<<endl;
      }
    }
  }
  return que1.top();
}

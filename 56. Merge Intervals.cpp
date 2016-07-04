struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


class Solution {
private:
  static bool compare(Interval &a,Interval &b){
    return a.start<b.start;
  }
public:
  bool is_overlop(Interval a, Interval b){
    if(a.start>b.end || a.end<b.start) return false;
    return true;
  }

  vector<Interval> merge(vector<Interval>& intervals_) {
    vector<Interval> ret;
    vector<Interval> intervals;
    for(int i=0;i<intervals_.size();i++)
      intervals.push_back(intervals_[i]);
    sort(intervals.begin(),intervals.end(),compare);
    int i=0;
    while(i<intervals.size()){
      Interval temp(intervals[i].start,intervals[i].end);
      i++;
      while(i<intervals.size() && is_overlop(temp,intervals[i])){
        temp.end=max(intervals[i].end,temp.end);
        i++;
      }
      ret.push_back(temp);
    }
    return ret;
  }
};

sort中的比较函数compare要声明为静态成员函数或全局函数，不能作为普通成员函数，否则会报错。
Line 26: invalid use of non-static member function 因为：非静态成员函数是依赖于具体对象的，而std::sort这类函数是全局的，
因此无法再sort中调用非静态成员函数。静态成员函数或者全局函数是不依赖于具体对象的,
可以独立访问，无须创建任何对象实例就可以访问。同时静态成员函数不可以调用类的非静态成员。

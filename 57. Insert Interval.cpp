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

  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> ret(intervals);
    ret.push_back(newInterval);
    for(int i=ret.size()-1;i>=1;i--){
      if(compare(ret[i],ret[i-1])) swap(ret[i],ret[i-1]);
    }
    ret=merge(ret);
    return ret;
  }
};

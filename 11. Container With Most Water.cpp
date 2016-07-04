int maxArea(vector<int>& height) {
  int reMax=0,lo=0,hi=height.size()-1;
  while(lo<hi){
    int area=(hi-lo)*min(height[lo],height[hi]);
    if(reMax<area) reMax=area;
    if(height[lo]<height[hi]) lo++;
    else hi--;
  }
  return reMax;
}

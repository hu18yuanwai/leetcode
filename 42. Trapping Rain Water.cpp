class Solution {
public:
  int trap(vector<int>& height) {
        if(height.size()<1) return 0;
        vector<int>leftmost(height.size());
        vector<int>rightmost(height.size());
        int max=0;
        for(int i=0;i<height.size();i++){
          leftmost[i]=max;
          if(max<height[i]) max=height[i];
        }

        max=0;
        for(int i=height.size()-1;i>=0;i--){
          rightmost[i]=max;
          if(max<height[i]) max=height[i];
        }

        int sumWater=0;
        for(int i=0;i<height.size();i++){
          int area=min(leftmost[i],rightmost[i])-height[i];
          if(area>0) sumWater+=area;
        }
        return sumWater;
  }
};

class Solution {
public:
    int trap(int a[], int n) {
        stack<pair<int, int>> s;
        int water = 0;
        for (int i = 0; i < n; ++i) {
            int height = 0;
            // 将栈里比当前元素矮或等高的元素全部处理掉
            while (!s.empty()) {
                int bar = s.top().first;
                int pos = s.top().second;
                // bar, height, a[i] 三者夹成的凹陷
                water += (min(bar, a[i]) - height) * (i - pos - 1);
                height = bar;
                if (a[i] < bar) // 碰到了比当前元素高的，跳出循环
                    break;
                else
                s.pop(); // 弹出栈顶，因为该元素处理完了，不再需要了
            }
            s.push(make_pair(a[i], i));
        }
        return water;
    }
};


class Solution {
public:
    //时间复杂度 O(n)，空间复杂度 O(1)
    int trap(int A[], int n) {
        // 最高的柱子，将数组分为两半
        int max = 0;
        for (int i = 0; i < n; i++){
            if (A[i] > A[max]) max = i;
        }
        int water = 0;
        for (int i = 0, leftMaxHeight = 0; i < max; i++){
            if (A[i] > leftMaxHeight){
                leftMaxHeight = A[i];
            }
            else {
                water += leftMaxHeight - A[i];
            }
        }
        for (int i = n - 1, rightMaxHeight = 0; i > max; i--){
            if (A[i] > rightMaxHeight){
                rightMaxHeight = A[i];
            }
            else{
                water += rightMaxHeight - A[i];
            }
        }
        return water;
    }
};



 class Solution
  {
  public:
     int trap(int A[], int n)
      {
         int res = 0, l = 0, r = n - 1;

         while(l < r)
         {
             int minh = min(A[l], A[r]);
             if(A[l] == minh)
                 while(++ l < r && A[l] < minh)
                                res += minh - A[l];
             else
                while(l < -- r && A[r] < minh)
                    res += minh - A[r];
         }

         return res;
     }
 }

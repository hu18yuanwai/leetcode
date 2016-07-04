//class Solution {
public:
    int binary_search(vector<int> &nums, int target){
        int start=0;
        int end=nums.size()-1;
        int mid;
        while(start<=end){
            mid=((end-start)>>1)+start;
            if(nums[mid]>target) end=mid-1;
            else if(nums[mid]<target) start=mid+1;
            else return -2;
        }
        if(nums[mid]>target) return mid-1;
        return mid;
    }

int binary_search_2(vector<vector<int>> &nums,int col,int target){
        int start=0;
        int end=nums.size()-1;
        int mid;
        while(start<=end){
            mid=((end-start)>>1)+start;
            if(nums[mid][col]>target) end=mid-1;
            else if(nums[mid][col]<target) start=mid+1;
            else return -2;
        }
        if(nums[mid][col]>target) return mid-1;
        return mid;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        if(matrix[0].size()==0) return false;
        if(target<matrix[0][0]) return false;
        int y=binary_search_2(matrix,0,target);
        int x=binary_search(matrix[0],target);
        if(y==-2 || x==-2) return true;
        int xx=binary_search(matrix[y],target);
        int yy=binary_search_2(matrix,x,target);
        if(xx==-2 || y==-2) return true;
        return false;
    }
};


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0) return false;
        
        int i=0, j=matrix[0].size()-1;
        
        while(i<matrix.size() && j>=0) {
            int x = matrix[i][j];
            if(target == x) return true;
            else if(target < x) --j;
            else ++i;
        }
        return false;
    }
};

http://articles.leetcode.com/searching-2d-sorted-matrix
#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
 

class NumArray {
public:
    NumArray(vector<int> &nums) {
        for(int i=0;i<nums.size();i++){
        	int sumNum=0;
        	for(int j=i;j<nums.size();j++){
        		sumNum+=nums[j];
        		index newIndex(i,j);
        		sum[newIndex]=sumNum;
        	}
        }
    }

    int sumRange(int i, int j) {
        index newIndex(i,j);
        return sum[newIndex];
    }
private:
	struct index{
		int i;
		int j;
		index(int a,int b):i(a),j(b){}
		bool operator<(const index Ind)const {
			if(this->i<Ind.i) 
				return true;
			else{
				if(this->i==Ind.i && this->j<Ind.j)
					return true;
				return false;
			} 
		}
	};
	map<index,int>sum;
};// can't pass the test.


class NumArray {
public:
    NumArray(vector<int> &nums) {
		int sum=0;
        for(int i=0;i<nums.size();i++){
			sum+=nums[i];
			result.push_back(sum);
		}
    }

    int sumRange(int i, int j) {
		if(0==i){
			return result[j];
		}
		else if(i<0 || i>=result.size() || j<0 || j>=result.size()){
			return 0;
		}
		else{
			return result[j]-result[i-1];
		}
    }
private:
	vector<int>result;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

int main(){
	vector<int>nums;
	for(int i=0;i<9;i++) nums.push_back(i*i);
	NumArray numsArray(nums);
	cout<<numsArray.sumRange(0, 1)<<endl;
	cout<<numsArray.sumRange(0, 6)<<endl;;
	return 0;
}
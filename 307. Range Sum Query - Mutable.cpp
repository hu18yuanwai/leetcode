class NumArray {
public:
    void update(int i, int val) {
    	int i_num=result[i]-result[i-1];
    	int cha=val-i_num;
        for(int j=i;j<result.size();j++)
        	result[j]+=cha;
    }

  
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
// numArray.update(1, 10);
// numArray.sumRange(1, 2);


//Sqrt decomposition
class NumArray {
public:
    NumArray(vector<int> &nums) {
    	for(int i=0;i<nums.size();i++)
    		this->nums.push_back(nums[i]);
        len=(int)sqrt(nums.size());
        for(int i=0;i<len;i++)
        	result.push_back(0);
        for(int i=0;i<nums.size();i++)
        	result[i/len]+=nums[i];
    }

    void update(int i, int val) {
        result[i/len]=result[i/len]+val-nums[i];
        nums[i]=val; 
    }

    int sumRange(int i, int j) {
    	int sum = 0;
    	int startBlock = i / len;
    	int endBlock = j / len;
    	if (startBlock == endBlock) {
        	for (int k = i; k <= j; k++)
            	sum += nums[k];
    	} else {
        	for (int k = i; k <= (startBlock + 1) * len - 1; k++)
            	sum += nums[k];
        	for (int k = startBlock + 1; k <= endBlock - 1; k++)
            	sum += result[k];
        	for (int k = endBlock * len; k <= j; k++)
            	sum += nums[k];
    }
    	return sum;
    }
private:
	vector<int>result;
	int len;
	vector<int>nums;
};

//Segment tree

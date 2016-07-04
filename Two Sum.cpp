vector<int> twoSum(vector<int>& nums, int target) {
	vector<int>index;
	for(int i=0;i<nums.size();++i){
		for(int j=i+1;j<nums.size();++i){
			if(nums[i]+nums[j]==target){
				index.push_back(i+1);
				index.push_back(i+2);
			}
		}
	}
	return index;		
}


bool find(vector<int>&nums,int begin,int end,const int key){
	int mid;
	if(begin>end)
		return false;
	while(begin<=end){
		int mid=(begin+end)/2;
		if(nums[mid]==key)
			return true;
		else if(nums[mid]<key)
			begin=mid+1;
		else if(nums[mid]>key)
			end=mid-1;
	}
	return false;
}

vector<int> twoSum(vector<int>& nums, int target){
	vector<int>copyNums;
	vector<int>index;
	int number1,number2;
	for(int i=0;i<nums.size();++i){
		copyNums.push_back(nums[i]);
	}

	sort(copyNums.begin(),copyNums.end());

	for(int i=0;i<copyNums.size();i++)
		cout<<copyNums[i]<<" ";
	cout<<endl;

	for(int i=0;i<copyNums.size();++i){
		if(find(copyNums,0,copyNums.size(),target-copyNums[i])){
			number1=target-copyNums[i];
			number2=copyNums[i];
			break;
		}
	}
	cout<<"number: "<<number1<<" "<<number2<<endl;

	for(int i=0;i<nums.size();++i){
		if(nums[i]==number1||nums[i]==number2)
			index.push_back(i+1);
	}
	return index;
}
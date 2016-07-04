class Solution {
public:
    int maxProfit(vector<int>& prices) {
	int len=prices.size();
	if(len==0||len==1)
		return 0;
	int temp;
	vector<int>fn(len);
	fn[0]=0;
	for(int i=1;i<len;++i){
		temp=prices[i]-prices[i-1];
		if(fn[i-1]<0){
			fn[i]=temp;
		}
		else{
			if(fn[i-1]+temp<0)
				fn[i]=0;
			else
				fn[i]=fn[i-1]+temp;
		}
	}
	
	int max=0;	
	for(int i=0;i<len;++i){
		//cout<<fn[i]<<" ";
		if(max<fn[i])
			max=fn[i]; 
	}
	//cout<<endl;
	return max;
}
};
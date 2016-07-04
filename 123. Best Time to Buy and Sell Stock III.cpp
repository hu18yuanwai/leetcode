class Solution {
public:
	int maxProfit_Once(vector<int>& prices,int be,int end) {
	int len=end-be+1;
	if(len==0||len==1)
		return 0;
	int temp;
	vector<int>fn(len);
	fn[0]=0;
	for(int i=be+1;i<end;++i){
		temp=prices[i]-prices[i-1];
		if(fn[i-be-1]<0){
			fn[i-be]=temp;
		}
		else{
			if(fn[i-be-1]+temp<0)
				fn[i-be]=0;
			else
				fn[i-be]=fn[i-be-1]+temp;
		}
	}
	
	int maxN=0;	
	for(int i=0;i<len;++i){
		if(maxN<fn[i])
			maxN=fn[i]; 
	}
	return maxN;
	}

    int maxProfit(vector<int>& prices) {
       if(prices.size()<4) return 0;
       int maxN=0;
       for(int i=0;i<prices.size();i++){
       	maxN=max(maxN,maxProfit_Once(prices,0,i)+maxProfit_Once(prices,i,prices.size()));
       }
       return maxN;
    }
};
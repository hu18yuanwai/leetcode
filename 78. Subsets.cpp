class Solution {
public:
	void backTrack(vector<vector<int>>& ret,vector<int>& cur,vector<int>&nums,int n,int k,int N){
		int times=0;
		for(int i=0;i<N;i++) times+=cur[i];
		if(N>=n){
			if(times==k){
				vector<int> temp;
				for(int i=0;i<cur.size();i++){
					if(cur[i]){
						temp.push_back(nums[i]);
					}
				}
				ret.push_back(temp);
			}
		}
		else{
			for(int i=0;i<=1;i++){
				cur[N]=i;
				if(k>=times+cur[N])
					backTrack(ret,cur,nums,n,k,N+1);
			}
		}
	}

    vector<vector<int>> combine(vector<int> nums, int k) {
        vector<vector<int>> ret;
        int n=nums.size();
        vector<int>cur(n,0);
        backTrack(ret,cur,nums,n,k,0);
        return ret;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
    	vector<vector<int>> ret;
    	for(int i=0;i<=nums.size();i++){
    		vector<vector<int>> tempRet=combine(nums,i);
    		for(int j=0;j<tempRet.size();j++)
    			ret.push_back(tempRet[j]);
    	}
    	return ret;
    }
};

//更加简洁的代码

class Solution {
public:
	void backTrack(vector<vector<int>>& ret, vector<int>& nums,vector<int>& curSet,int ii,int N){
		if(ii==0) ret.push_back(curSet);
		else{
			for(int i=N;i<nums.size();i++){
				curSet.push_back(nums[i]);
				backTrack(ret,nums,curSet,ii-1,i+1);
				curSet.pop_back();
			}
		}
	}
    vector<vector<int>> subsets(vector<int>& nums) {
    	sort(nums.begin(),nums.end());
        vector<int>curSet;
        vector<vector<int>> ret;
        for(int i=0;i<nums.size();i++){
        	backTrack(ret,nums,curSet,i,0);
        }
        ret.push_back(nums);
        return ret;
    }
};
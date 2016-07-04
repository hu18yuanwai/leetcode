class Solution {
public:
	void backTrack(vector<vector<int>>& ret, vector<int>& nums,vector<int>& curSet,int ii,int N){
		if(ii==0) ret.push_back(curSet);
		else{
			for(int i=N;i<nums.size();i++){
				if(i!=N && nums[i]==nums[i-1]) continue;
				curSet.push_back(nums[i]);
				backTrack(ret,nums,curSet,ii-1,i+1);
				curSet.pop_back();
			}
		}
	}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
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
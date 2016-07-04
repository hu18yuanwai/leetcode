class Solution {
public:
	void backTrack(vector<vector<int>>& ret,vector<int>& cur,int n,int k,int N){
		int times=0;
		for(int i=0;i<N;i++) times+=cur[i];
		if(N>=n){
			if(times==k){
				vector<int> temp;
				for(int i=0;i<cur.size();i++){
					if(cur[i]){
						temp.push_back(i+1);
					}
				}
				ret.push_back(temp);
			}
		}
		else{
			for(int i=0;i<=1;i++){
				cur[N]=i;
				if(k>=times+cur[N])
					backTrack(ret,cur,n,k,N+1);
			}
		}
	}

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int>cur(n,0);
        backTrack(ret,cur,n,k,0);
        return ret;
    }
};
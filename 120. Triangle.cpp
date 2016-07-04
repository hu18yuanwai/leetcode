class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    	if(triangle.size()==0) return 0;
        vector<int> dis;
        dis.push_back(triangle[0][0]);
        for(int i=1;i<triangle.size();i++){
        	dis.push_back(INT_MAX);
        	int len=dis.size();
        	dis[len-1]=min(dis[len-1],dis[len-2]+triangle[i][len-1]);
        	for(int j=len-2;j>=1;j--)
        		dis[j]=triangle[i][j]+min(dis[j],dis[j-1]);
        	dis[0]=triangle[i][0]+dis[0];
        }

        int min=INT_MAX;
        for(int i=0;i<dis.size();i++)
        	if(min>dis[i]) min=dis[i];
        return min;
    }
};
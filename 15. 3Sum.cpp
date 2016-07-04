#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool find_num( vector<int>& nums,int begin,int end,int target){
	if(begin>=end)
		return false;
	while(begin<end){
		int mid=(begin+end)/2;
		if(nums[mid]==target)
			return true;
		else if(nums[mid]<target)
			begin=mid+1;
		else
			end=mid;
	}
	return false;
}

vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> >result;
        if(nums.size()==0) return result;
        for(int i=0;i<nums.size()-2;i++){
        	if(nums[i]>0) break;
        	if(i>0 && nums[i]==nums[i-1]) continue;
        	for(int j=i+1;j<nums.size()-1;j++){
        		if(nums[i]+nums[j]>0) break;
        		if(j>i+1 && nums[j]==nums[j-1]) continue;
        		if( find_num(nums,j+1,nums.size(),(-nums[i]-nums[j])) ){
        			vector<int> re;
        			re.push_back(nums[i]);
        			re.push_back(nums[j]);
        			re.push_back((-nums[i]-nums[j]));
        			result.push_back(re);
				}
			}
		}
    return result;
}

int main(){
	int len;
	cin>>len;
	vector<int>nums;
	while(len--){
		int a;
		cin>>a;
		nums.push_back(a);
	}
	vector<vector<int> > tree=threeSum(nums);
	for(int i=0;i<tree.size();i++){
		for(int j=0;j<3;j++)
			cout<<tree[i][j]<<" ";
		cout<<endl;
		}

	cin>>len;
	return 0;
}

//第二种方法，双指针
vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> >result;
        if(nums.size()==0) return result;
        for(int i=0;i<nums.size()-2;i++){
        	if(nums[i]>0) break;
        	if(i>0 && nums[i]==nums[i-1]) continue;
          int left=i+1,right=nums.size()-1;
					while(left<right){
						if(nums[left]+nums[right]==-nums[i]){
							vector<int>re;
							re.push_back(nums[i]);
							re.push_back(nums[left]);
							re.push_back(nums[right]);
							result.push_back(re);
							while(left<nums.size() && nums[left]==nums[left-1]){
								left++;
							}
							while(right>=0 && nums[right]==nums[right+1]){
								right--;
							}
						}

						else if(nums[left]+nums[right]<-nums[i]) left++;
						else right--;
					}
			}
    return result;
}

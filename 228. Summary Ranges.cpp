class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector <string> ret;
        int front=0,behind=0;
        while(front<nums.size() && behind<nums.size()){
        	behind=front;
        	while(behind<nums.size()-1 && nums[behind]==nums[behind+1]-1)
        		behind++;
        	if(front==behind){
        		stringstream ss;
        		ss<<nums[behind];
        		ret.push_back(ss.str());
        		ss.str("");
        	}
        	else{
        		string s;
        		stringstream ss;
        		ss<<nums[front];
        		s+=ss.str();
        		ss.str("");
        		s+="->";
        		ss<<nums[behind];
        		s+=ss.str();
        		ss.str("");
        		ret.push_back(s);
        	}
        	front=behind+1;
        }
        return ret;
    }
};

//另外一种int转化为string的方法
string format(int begin, int end)
	{
		char buffer[32];
		if (end == begin)
		{
			sprintf(buffer, "%d", begin);
		}else{
			sprintf(buffer, "%d->%d", begin, end);
		}
		return string(buffer);
	}
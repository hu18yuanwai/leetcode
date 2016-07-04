
http://www.cnblogs.com/felixfang/p/3814463.html
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	int i=0,left=0,beg=0,total=0;
    	while(i<gas.size()){
    		left+=gas[i]-cost[i];
    		total+=gas[i]-cost[i];
    		if(left<0){
    			beg=i+1;
    			left=0;
    		}
    		i++;
    	}
    	return total>=0?beg:-1;
    }
};

//just pass narrowly.
class Solution {
public:
	struct gasRemain{
		int gasId;
		int remain;
		gasRemain(int a,int b):gasId(a),remain(b){}
	};

	static bool cmp(gasRemain a,gasRemain b){
		return a.remain>b.remain;
	}

	bool start(int index,vector<int>& gas, vector<int>& cost){
		int TankCapcity=0;
		for(int i=index;i<gas.size();i++){
			TankCapcity=TankCapcity+gas[i]-cost[i];
			if(TankCapcity<0)
				return false;
		}

		for(int i=0;i<index;i++){
			TankCapcity=TankCapcity+gas[i]-cost[i];
			if(TankCapcity<0)
				return false;
		}
		return true;
	}

	
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.size()==0 || cost.size()==0 || gas.size()!=cost.size())
        	return -1;
        vector<gasRemain> data;
        for(int i=0;i<gas.size();i++){
        	data.push_back(gasRemain(i,gas[i]-cost[i]));
        }

        sort(data.begin(),data.end(),cmp);

        for(int i=0;i<data.size();i++){
        	if(start(data[i].gasId,gas,cost))
        		return data[i].gasId;
        }

        return -1;
    }
};


//o(n^2) is not accepted.
class Solution {
public:
	bool start(int index,vector<int>& gas, vector<int>& cost){
		int TankCapcity=0;
		for(int i=index;i<gas.size();i++){
			TankCapcity=TankCapcity+gas[i]-cost[i];
			if(TankCapcity<0)
				return false;
		}

		for(int i=0;i<index;i++){
			TankCapcity=TankCapcity+gas[i]-cost[i];
			if(TankCapcity<0)
				return false;
		}
		return true;
	}

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i=0;i<gas.size();i++){
        	if(start(i,gas,cost))
        		return i;
        }
        return -1;
    }
};
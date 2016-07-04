/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution
{
public:
    int maxPoints(vector<Point>& points)
    {
        if (points.size() < 3)
        {
            return points.size();
        }

        sort(points.begin(), points.end(), [](Point &pt1, Point &pt2) { return pt1.x == pt2.x ? pt1.y < pt2. y : pt1.x < pt2.x; });
        int maxPts = 0;
        for (int i = 0; i < points.size(); i++)
        {
            if (i > 0 && samePoint(points[i], points[i - 1]))  // pass duplicates.
            {
                continue;
            }

            unordered_map<double, int> ptsOnLines;
            int originPts = 1;
            for (int j = i + 1; j < points.size(); j++)
            {
                if (samePoint(points[i], points[j]))
                {
                    originPts++;
                }
                else if (verticleLine(points[i], points[j]))
                {
                    ptsOnLines[numeric_limits<double>::infinity()]++;
                }
                else
                {
                    ptsOnLines[slope(points[i], points[j])]++;
                }
            }

            using T = unordered_map<double, int>::value_type;
            auto itr = max_element(ptsOnLines.begin(), ptsOnLines.end(), [](const T &p1, const T &p2) { return p1.second < p2.second; });
            maxPts = max(maxPts, originPts + (itr == ptsOnLines.end() ? 0 : itr->second));
        }
        return maxPts;
    }

private:
    inline bool samePoint(const Point &pt1, const Point &pt2)
    {
        return pt1.x == pt2.x && pt1.y == pt2.y;
    }

    inline bool verticleLine(const Point &pt1, const Point &pt2)
    {
        return pt1.x == pt2.x && pt1.y != pt2.y;
    }

    inline double slope(const Point &pt1, const Point &pt2)
    {
        return ((double) pt2.y - pt1.y) / (pt2.x - pt1.x);
    }
};
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size()<3) return points.size();
        int ret=0;
        for(int i=0;i<points.size();i++){
        	int maxc=1;
        	map<double,int> count;
        	int coincide=0;
        	int vnt=0;
        	for(int j=0;j<points.size();i++){ // there is not i, fucking >>>>>>>>>>>>>>>>>>>>>
        		if(i!=j){
        			double x1=points[i].x-points[j].x;
        			double x2=points[i].y-points[j].y;
        			if(x1==0 && x2==0) coincide++;
        			else if( x1==0){
        				if(vnt==0) vnt=2;
        				else vnt++;
        				maxc=max(maxc,vnt);
        			}
        			else{
        				double k=x2/x1;
        				if(count.find(k)==count.end()) count[k]=2;
        				else count[k]++;
        				maxc=max(maxc,count[k]);
        			}
        		}
        	}
        	ret=max(ret,maxc+coincide);
        }
        return ret;
    }
};


 // the worry solution 
 #define DBL_MAX 1.7976931348623158e+308 
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        map<Line,int> count;
        for(int i=0;i<points.size();i++){
        	for(int j=0;j<points.size();j++){
        		if(i!=j){
        			double k,b;
        			double x1=points[i].x;
        			double y1=points[i].y;
        			double x2=points[j].x;
        			double y2=points[j].y;
        			if(x1==x2){
        				k=DBL_MAX;
        				b=x1;
        			}
        			else{
        				k=(y2-y1)/(x2*1.0-x1);
        				b=(y1*x2-y2*x1)/(x2*1.0-x1);
        			}
        			Line line(k,b);
        			if(count.find(line)!=count.end()){
        				count[line]++;
        			}
        			else{
        				count[line]=0;
        			}
        		}
        	}
        }
        int max=INT_MAX;
        for(map<Line,int>::iterator mapi=count.begin();mapi!=count.end();mapi++){
        	if(max<mapi->second)
        		max=mapi->second;
        }
        return max;
    }
 private:
 	struct Line{
 		double a;
 		double b;
 		Line():a(0.),b(0.){}
 		Line(double x,double y):a(x),b(y){}
 		bool operator =(Line l2){
 			if(dCmp(this.x,l2.x)==0 && dCmp(this.y,l2.y)==0) 
 				return 1;
 			return 0;
 		}
 		int dCmp(double a, double b){
    		if (a < b - DBL_EPSILON)
        		return -1;
    		else if (a > b + DBL_EPSILON)
        		return 1;
    		else
        		return 0;
		}
 	};
};
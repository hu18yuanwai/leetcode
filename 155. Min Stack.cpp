class MinStack {
public:
    /** initialize your data structure here. */

    void push(int x) {
        num.push_back(x);
        if(minNum.size()>0){
            if(x<minNum[minNum.size()-1]){
                minNum.push_back(x);
            }
            else{
                minNum.push_back(minNum[minNum.size()-1]);
            }
        }
        else
            minNum.push_back(x);
    }

    void pop() {
        if(num.size()>0){
            num.pop_back();
            minNum.pop_back();
        }
    }

    int top() {
        return num[num.size()-1];
    }

    int getMin() {
        return minNum[minNum.size()-1];
    }
private:
    vector<int> num;
    vector<int> minNum;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

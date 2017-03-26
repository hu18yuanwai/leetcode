class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        size=0;
    }

    int get(int key) {
        auto it = keyValueFrequency.find(key);
        if(it == keyValueFrequency.end()) return -1;
        int ret = it->second.first;
        int oldfreq= it->second.second++;
        frequencyList[oldfreq].erase(keyIterator[key]);
        frequencyList[oldfreq+1].push_back(key);
        keyIterator[key] = --frequencyList[oldfreq+1].end();
        if(frequencyList[minFreq].size()==0)
            minFreq++;
        return ret;
    }

    void put(int key, int value) {
        if(capacity<=0) return;
        int oldvalue = get(key);
        if(oldvalue!=-1){
            keyValueFrequency[key].first = value;
            return;
        }
        if(size>=capacity){
            int removeNum = frequencyList[minFreq].front();
            keyValueFrequency.erase(removeNum);
            keyIterator.erase(removeNum);
            frequencyList[minFreq].pop_front();
            size--;
        }
        keyValueFrequency[key] = {value,1};
        frequencyList[1].push_back(key);
        keyIterator[key] = --frequencyList[1].end();
        minFreq = 1;
        size++;
    }
private:
    int capacity;
    int size;
    int minFreq;
    typedef list<int> intList;
    typedef intList::iterator iLIterator;
    unordered_map<int,pair<int,int>> keyValueFrequency;
    unordered_map<int, iLIterator> keyIterator;
    unordered_map<int, intList> frequencyList;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

class NumberContainers {
public:
    map<int, set<int>>mst;
    map<int,int> mp;
    NumberContainers() {}
    
    void change(int index, int number) {
        if(mp.find(index) != mp.end()){
            int prev = mp[index];
            mst[prev].erase(index);
            if(mst[prev].empty()) mst.erase(prev);
            mp[index] = number;
            mst[number].insert(index);
        }
        else{
            mp[index] = number;
            mst[number].insert(index);
        }
    }
    
    int find(int number) {
        if(mst.find(number) != mst.end()){
            return *(mst[number].begin());
        }
        else return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
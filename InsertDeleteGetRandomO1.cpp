class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (map.find(val) == map.end()) {
            list.push_back(val);
            map.insert({val, list.size()-1});
            return true;
        }
        
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (map.find(val) == map.end()) {
            return false;
        }
        
        // swap the index with last element, delete last element
        int index = map[val];
        list[index] = list[list.size()-1];
        list.pop_back();
        map[list[index]] = index;
        map.erase(val);
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int index = rand() % list.size();
        return list[index];
    }
    
private:
    vector<int> list;   // store the elements, need indexed data structure for getRandom
    unordered_map<int, int> map;    // map elem -> index in list
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

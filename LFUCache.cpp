class LFUCache {
public:
    // map key to value and current frequency
    unordered_map<int, pair<int, int>> keyToValFreq;
    
    // map frequency to list of keys (used for O(1) deletion of LFU)
    unordered_map<int, list<int>> freqToKeys;
    
    // keep track of where in freqToKeys the key is in the list
    // to delete it in O(1)
    unordered_map<int, list<int>::iterator> keyIterator;
    
    int capacity;
    int minFreq;
    
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 1;
    }
    
    int get(int key) {
        if (keyToValFreq.find(key) == keyToValFreq.end()) {
            return -1;
        }
        
        // move this KVP to higher frequency
        int freq = keyToValFreq[key].second;
        freqToKeys[freq].erase(keyIterator[key]);
        freqToKeys[++freq].emplace_front(key);
        keyToValFreq[key].second = freq;
        
        // update key iterator
        keyIterator[key] = freqToKeys[freq].begin();
        
        // update minFreq if this was the last key with min frequency
        if (freqToKeys[minFreq].empty()) {
            minFreq = freq;
        }
        
        return keyToValFreq[key].first;
    }
    
    void put(int key, int value) {
        if (capacity <= 0) return;
        
        // insert the key if doesn't exist
        // use get() to automatically perform counter increment
        if (get(key) == -1) {
            // check if we're out of capacity
            if (keyToValFreq.size() == capacity) {
                int lfuKey = freqToKeys[minFreq].back();
                keyToValFreq.erase(lfuKey);
                keyIterator.erase(lfuKey);
                freqToKeys[minFreq].pop_back();
            }
        
            minFreq = 1;
            keyToValFreq[key] = make_pair(value, minFreq);
            freqToKeys[minFreq].emplace_front(key);
            keyIterator[key] = freqToKeys[minFreq].begin();
        } else {
            keyToValFreq[key].first = value;
        }
    }
    
    // void debug() {
    //     for (const auto kvp : freqToKeys) {
    //         cout << "\tfreq: " << kvp.first << endl;
    //         cout << "\t";
    //         for (int key : kvp.second) {
    //             cout << key << ",";
    //         }
    //         cout << endl;
    //     }
    // }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

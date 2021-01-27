class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // greedily use up highest frequency tasks
        // A__A__A__A__A__A    we also have 4B, 2C 2D 2E 2F 2G...
        // ABCABCABDABDABEAFBEF
        // lower frequencies don't matter since we can insert them anywhere in the task sequence
        // and guarantee each of them is separated by at least n blocks as their frequency is much less 
        // than A
        
        vector<int> frequencies(26, 0);
        for (char t : tasks) {
            frequencies[t-'A']++;
        }
        
        sort(frequencies.begin(), frequencies.end(), [](const int a, const int b) {
            return a > b;
        });
        
        int f = frequencies[0];
        int idle =  n * (frequencies[0]-1);
        for (int i = 1; idle >= 0 && i < frequencies.size(); i++) {
            idle -= min(f-1, frequencies[i]);   // there are only f-1 gaps to fill
        }
        
        idle = max(0, idle);
        
        return idle + tasks.size();
    }
};

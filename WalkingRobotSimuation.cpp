class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obs;
        for (vector<int>& o : obstacles) {
            obs.insert(encodeCoord(o[0], o[1]));
        }
        
        int ans = 0;
        int x=0, y=0;
        int d = 0; //0 = N, 1 = E, 2 = S, 3 = W
        for (int com : commands) {
            if (com == -2) {
                d = (d-1 + 4)%4; // we want positive mod only
            } else if (com == -1) {
                d = (d+1 + 4)%4; // we want positive mod only
            } else {
                move(x, y, com, d, obs);
            }
            
            ans = max(ans, x*x + y*y);
        }
        
        return ans;
    }
    
    void move(int& x, int& y, int len, int d, unordered_set<string>& obs) {
        if (d == 0) {
            while (obs.find(encodeCoord(x, y+1)) == obs.end() && len-- > 0) y++;
        } else if (d == 1) {
            while (obs.find(encodeCoord(x+1, y)) == obs.end() && len-- > 0) x++;
        } else if (d == 2) {
            while (obs.find(encodeCoord(x, y-1)) == obs.end() && len-- > 0) y--;
        } else {
            while (obs.find(encodeCoord(x-1, y)) == obs.end() && len-- > 0) x--;
        }
    }
    
    string encodeCoord(int x, int y) {
        return to_string(x) + "," + to_string(y);
    }
};

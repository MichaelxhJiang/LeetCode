class Solution {
public:
    vector<string> ans;
    string nums;
    int target;
    
    vector<string> addOperators(string nums, int target) {
        this->nums = nums;
        this->target = target;
        
        vector<string> sequence;
        recur(0, 0, 0, sequence, 0);
        
        return ans;
    }
    
    // work left to right, inserting operators in all possible ways
    // keep track of value of previously inserted operators
    void recur(int index, long long prevTerm, long long curTerm, vector<string>& sequence, long long curVal) {
        if (index == nums.size()) {
            if (curVal == target && curTerm == 0) {
                string concat = "";
                // ignore first + sign
                for (int i = 1; i < sequence.size(); i++) 
                    concat += sequence[i];
                ans.push_back(concat);
            }
            return;
        }
        
        // do this after index check so no overflow
        curTerm = curTerm*10 + nums[index]-'0';
        
        // expand curTerm
        // note: expanding 0 -> 01 is invalid
        if (curTerm > 0) {
            recur(index+1, prevTerm, curTerm, sequence, curVal);
        }
        
        // add (also used to add the first term into the sequence)
        sequence.push_back("+");
        sequence.push_back(to_string(curTerm));
        recur(index+1, curTerm, 0, sequence, curVal+curTerm);
        sequence.pop_back();
        sequence.pop_back();

        if (sequence.size() > 0) {
            // subtract
            sequence.push_back("-");
            sequence.push_back(to_string(curTerm));
            recur(index+1, -curTerm, 0, sequence, curVal-curTerm);
            sequence.pop_back();
            sequence.pop_back();

            // multiply
            sequence.push_back("*");
            sequence.push_back(to_string(curTerm));
            recur(index+1, prevTerm*curTerm, 0, sequence, (curVal-prevTerm)+(prevTerm*curTerm));
            sequence.pop_back();
            sequence.pop_back();
        }
    }
};

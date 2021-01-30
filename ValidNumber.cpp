class Solution {
public:
    bool isNumber(string s) {
        string first;
        string second;
        bool e = false;
        // check if e is in s
        if (s.find("e") != string::npos) {
            first = string(s.begin(), s.begin() + s.find("e"));
            second = string(s.begin() + s.find("e") + 1, s.end());
            e = true;
        } else if (s.find("E") != string::npos) {
            first = string(s.begin(), s.begin() + s.find("E"));
            second = string(s.begin() + s.find("E") + 1, s.end());
            e = true;
        } else {
            first = s;
            second = "";
        }
        
        cout << first << endl;
        cout << second << endl;
        
        return first != "" && (isInteger(first) || isDecimal(first)) && (!e || isInteger(second));
    }
    
    bool isInteger(string s) {
        int index = 0;
        bool num = false;
        
        if (s == "") return false;
        
        if (s[0] == '+' || s[0] == '-') index++;
        while (index < s.size()) {
            if (!isdigit(s[index])) return false;
            else num = true;
            index++;
        }
        
        if (!num) return false;
        
        return true;
    }
    
    bool isDecimal(string s) {
        int index = 0;
        bool dot = false;
        bool num = false;
        if (s[0] == '.') {
            dot = true;
            index++;
        }
        if (s[0] == '+' || s[0] == '-') index++;
        
        while (index < s.size()) {
            if (s[index] == '.') {
                if (!dot) {
                    dot = true;
                } else {
                    return false;
                }
            } else if (!isdigit(s[index])) {
                return false; 
            } else {
                num = true;
            }
            
            index++;
        }
        
        if (!num) return false;
        
        return true;
    }
};

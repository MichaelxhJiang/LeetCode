class Solution {
public:
    int myAtoi(string str) {
        string substring = str;
        for (int i = 0; i < str.length() && str.at(i) == ' '; i++) {
            substring = str.substr(i+1);
        }
        
        if (substring.length() == 0) return 0;
        
        bool neg = false;
        
        if (substring.at(0) == '-') {
            neg = true;
            substring = substring.substr(1);
        } else if (substring.at(0) == '+') {
            substring = substring.substr(1);
        }
        
        long val = 0;
        
        for (int i = 0; i < substring.length(); i++) {
            if (isdigit(substring.at(i))) {
                val *= 10;
                val += substring.at(i) - '0';
                if (val > INT_MAX && !neg) return INT_MAX;
                if (val*-1 < INT_MIN && neg) return INT_MIN;
            } else {
                break;
            }
        }
        
        val *= neg ? -1 : 1;
        
        return val;
    }
};

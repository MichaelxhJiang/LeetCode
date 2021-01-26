class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int i1 = num1.size()-1;
        int i2 = num2.size()-1;
        
        bool carry = false;
        while (i1 >= 0 && i2 >= 0) {
            int cur = 0;
            if (carry) cur += 1;
            cur += (num1[i1] - '0') + (num2[i2] - '0');
            
            ans += (cur%10 + '0');
            if (cur >= 10) carry = true;
            else carry = false;
            
            i1--;
            i2--;
        }
        
        while (i1 >= 0) {
            int cur = 0;
            if (carry) cur += 1;
            cur += num1[i1]-'0';
            
            ans += (cur%10 + '0');
            if (cur >= 10) carry = true;
            else carry = false;
            
            i1--;
        }
        
        while (i2 >= 0) {
            int cur = 0;
            if (carry) cur += 1;
            cur += num2[i2]-'0';
            
            ans += (cur%10 + '0');
            if (cur >= 10) carry = true;
            else carry = false;
            
            i2--;
        }
        
        if (carry) ans += "1";
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

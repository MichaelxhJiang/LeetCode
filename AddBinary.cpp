class Solution {
public:
    string addBinary(string a, string b) {
        int ia = a.size()-1;
        int ib = b.size()-1;
        
        bool carry = false;
        string ans = "";
        while (ia >= 0 && ib >= 0) {
            int sum = (a[ia] - '0') + (b[ib] - '0');
            if (carry) sum++;
            if (sum > 1) carry = true;
            else carry = false;
            ans += (sum%2 + '0');
            ia--;
            ib--;
        }
        
        while (ia >= 0) {
            int sum = a[ia] - '0';
            if (carry) sum++;
            if (sum > 1) carry = true;
            else carry = false;
            ans += (sum%2 + '0');
            ia--;
        }
        while (ib >= 0) {
            int sum = b[ib] - '0';
            if (carry) sum++;
            if (sum > 1) carry = true;
            else carry = false;
            ans += (sum%2 + '0');
            ib--;
        }
        if (carry) ans += '1';
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

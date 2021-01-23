class Solution {
public:
    int maximumSwap(int num) {
        // Greedy
        string digits = to_string(num);
        vector<int> last(10,-1);
        for (int i = 0; i < digits.size(); i++) {
            last[digits[i]-'0'] = i;
        }
        for (int i = 0; i < digits.size(); i++) {
            // scan to see if there exists a larger digit in a less significant digit
            // and swap with it
            for (int j = 9; j > digits[i]-'0'; j--) {
                if (last[j] > i) {
                    digits[last[j]] = digits[i];
                    digits[i] = j + '0';
                    return stoi(digits);
                }
            }
        }
        
        // current digits arrangement is already maximal
        return stoi(digits);
        
        // sort the digits greatest to lowest
        // scan left to right, swap at first discrepancy. If no discrepancy, don't swap
//         vector<int> sorted;
//         vector<int> digits;
//         int temp = num;
//         while (temp > 0) {
//             digits.push_back(temp % 10);
//             sorted.push_back(temp % 10);
//             temp /= 10;
//         }
//         sort(sorted.begin(), sorted.end());
        
//         for(int i = digits.size()-1; i >= 0; i--) {
//             if (digits[i] != sorted[i]) {
//                 //swap with least significant index that contains sorted element
//                 int index = 0;
//                 for (int j = 0; j < digits.size(); j++) {
//                     if (digits[j] == sorted[i]) {
//                         index = j;
//                         break;
//                     }
//                 }
//                 int t = digits[index];
//                 digits[index] = digits[i];
//                 digits[i] = t;
//                 break;
//             }
//         }
        
//         int ans = 0;
//         for (int i = digits.size()-1; i >= 0; i--) {
//             ans *= 10;
//             ans += digits[i];
//         }
        
//         return ans;
    }
};

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int ans = -1;
        int col = binaryMatrix.dimensions()[1];
        int row = binaryMatrix.dimensions()[0];
        int c = col-1;
        int r = 0;
        while (c >= 0 && r < row) {
            if (binaryMatrix.get(r, c) == 1) {
                ans = c;
                c--;
            } else {
                r++;
            }
        }
        
        return ans;
        
//         int col = binaryMatrix.dimensions()[1];
//         int row = binaryMatrix.dimensions()[0];
//         int ans = -1;
        
//         // binary search to find leftmost column
//         for (int r = 0; r < row; r++) {
//             int c1 = 0;
            
//             // shrink search space to the left of current best
//             int c2 = ans != -1 ? ans-1 : col-1; 
            
//             while (c1 <= c2) {
//                 int mid = (c1+c2)/2;

//                 if (binaryMatrix.get(r, mid) == 1) {
//                     if (ans == -1 || mid < ans) {
//                         ans = mid;
//                     }
//                     c2 = mid-1;
//                 } else {
//                     c1 = mid+1;
//                 }
//             }
//         }
        
//         return ans;
    }
};

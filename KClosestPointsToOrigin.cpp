class Solution {
public:
    vector<vector<int>> points;
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        // NOTE: quick sort is best for this problem because we don't have to return
        // the points in sorted order so we can leave some sections "partially" sorted
        this->points = points;
        sort(0, points.size()-1, K);
        return vector<vector<int>>(this->points.begin(), this->points.begin()+K);
    }
    
    void sort(int i, int j, int K) {
        if (i >= j) return;
        int k = rand() % (j-i+1) + i;
        swap(points[i], points[k]);
        int mid = partition(i, j);
        int leftLength = mid - i + 1;
        
        if (K < leftLength) {   
            sort(i, mid - 1, K);
        } else {
            // leave i->mid-1 section unsorted since we need
            // to return all those elements anyways
            sort(mid + 1, j, K - leftLength);
        }
    }
    
    int partition(int i, int j) {
        int ti = i;
        int pivot = dist(i);
        i++;
        
        while (true) {
            while (i < j && dist(i) <= pivot) i++;
            while (j >= i && dist(j) >= pivot) j--;
            
            if (i >= j) break;
            swap(points[i], points[j]);
        }
        
        swap(points[ti], points[j]);
        return j;
    }
    
    int dist(int i) {
        return points[i][0]*points[i][0] + points[i][1]*points[i][1];
    }
};

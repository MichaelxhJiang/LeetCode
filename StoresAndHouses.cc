#include <vector>
#include <iostream>

using namespace std;

int binarySearch(vector<int> stores, int key, int left, int right, int closestIndex) {
	if (left > right) return closestIndex;

	int mid = (left+right)/2;

	if (stores[mid] == key) return mid;
	else if (stores[mid] > key) {
		if (abs(stores[mid]-key) < abs(stores[closestIndex]-key)) {
			closestIndex = mid;
		}

		right = mid-1;
		return binarySearch(stores, key, left, right, closestIndex);
	} else {
		if (abs(stores[mid]-key) < abs(stores[closestIndex]-key)) {
			closestIndex = mid;
		}
		
		left = mid+1;
		return binarySearch(stores, key, left, right, closestIndex);
	}
}
vector<int> solution (vector<int> houses, vector<int> stores) {
	sort(stores.begin(), stores.end());

	vector<int> ans;

	for (int i = 0; i < houses.size(); i++) {
		int closestIndex = binarySearch(stores, houses[i], 0, stores.size()-1, 0);
		ans.push_back(stores[closestIndex]);
	}

	return ans;
}

int main () {
	vector<int> houses = {5, 10, 17};
	vector<int> stores = {1, 5, 20, 11, 16};

	vector<int> ans = solution(houses, stores);

	for (int i : ans) cout<<i<<endl;
}


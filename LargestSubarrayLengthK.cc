#include <vector>
#include <iostream>

using namespace std;

vector<int> solution (vector<int> arr, int k) {
	bool distinct = false;
	int max = arr[0];
	int max_index = 0;

	for (int i = 0; i < arr.size(); i++) {
		if (max < arr[i]) {
		       	max = arr[i];	
			max_index = i;
		}
	}

	vector<int> ans;

	for (int i = max_index; i < max_index + k; i++) {
		ans.push_back(arr[i]);
	}

	return ans;
}

int main (int argv, char* argc []) {
	vector<int> arr = {1, 2, 3, 6, 1, 2, 3, 1, 2, 5, 1, 2};
	vector<int> ans = solution(arr, 3);

	for (int i : ans) cout<<i<<endl;
}

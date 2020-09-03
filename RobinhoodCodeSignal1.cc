#include<vector>
#include <unordered_map>
#include <iostream>

using namespace std;


int rev(int n) {
	int r = 0;

	while (n) {
		r *= 10;
		r += n%10;
		n /= 10;
	}

	return r;
}

int solution(vector<int> arr) {
	int ans = 0;

	unordered_map<int, int> dict;

	// count all instances of arr[i] - rev(arr[i])
	for (int i : arr) {
		dict[i - rev(i)]++;
	}	

	// for each key k in dict, the number of combinations is k choose 2 + k	
	for (auto k : dict) {
		ans += (k.second * (k.second + 1)) / 2;	
	}

	return ans;
}

int main () {
	vector<int> input {1, 20, 2, 11};
	cout << solution(input) << endl;
}

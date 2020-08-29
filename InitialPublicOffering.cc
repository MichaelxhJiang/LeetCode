#include <vector>
#include <tuple>
#include <iostream>
#include <queue>


using namespace std;

struct Bid {
	int u;
	int sc;
	int bp;
	int ts;

	Bid(int n1, int n2, int n3, int n4) : u(n1), sc(n2), bp(n3), ts(n4) {}

	bool operator<(const Bid & other) const {
		if (bp == other.bp) {
			return ts > other.ts;
		}
		
		return bp < other.bp;
	}
};

vector<int> getUnallottedUsers(vector<vector<int>> bids, int totalShares) {
	vector<int> ans;
	priority_queue<Bid> pq;

	for (vector<int> bid : bids) {
		pq.push(Bid(bid[0], bid[1], bid[2], bid[3]));
	}

	while (totalShares > 0 && !pq.empty()) {
		Bid bid = pq.top();
		pq.pop();
		totalShares -= bid.sc;
	}

	while (!pq.empty()) {
		Bid bid = pq.top();
		pq.pop();
		ans.push_back(bid.u);
	}

	return ans;
}

int main() {
	vector<vector<int>> bids { {1, 5, 5, 0}, {2, 7, 8, 1}, {3, 7, 5, 1}, {4, 10, 3, 3} };
	int totalShares = 18;

	vector<int> ans = getUnallottedUsers(bids, totalShares);

	cout << "Ans: ";
	for (auto i : ans) cout << i << " ";
	cout << endl;
}

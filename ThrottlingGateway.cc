/*
Space innefficient if there are large gaps between time stamps
*/
int solution(vector<int> requestTime) {
	int size = requestTime.size();
	vector<int> prefixSum(requestTime[size-1], 0);
	map<int, int> count;
	for (int i = 0; i < size; i++) {
		count[requestTime[i]]++;
	}

	for (int i = requestTime[0]; i < requestTime[size-1]; i++) {
		count[i] += count[i-1];
	}

	int ans = 0;
	for (int i = 3; i < size; i++) {
		if (requestTime[i-3] == requestTime[i])	ans++;
		else if (count.find(requestTime[i] - 10) != count.end() && i+1 - count[requestTime[i]-10] > 20) ans++;
		else if (count.find(requestTime[i] - 60) != count.end() && i+1 - count[requestTime[i]-60] > 60) ans++;
	}

	return ans;
}

// Sliding Window approach
int solution (vector<int> requestTime) {
	int curSecond = requestTime[0];
	int curCount = 1;
	deque<int> count10 {requestTime[0]};
	deque<int> count60 {requestTime[0]}; 

	int ans = 0;

	for (int i = 1; i < requestTime.size(); i++) {
		//slide the windows forward
		while (requestTime[i] -	count10.front() > 10) count10.pop_front();
		while (requestTime[i] - count60.front() > 60) count60.pop_front();
		count10.push_back(requestTime[i]);
		count60.push_back(requestTime[i]);

		if (count10.size() > 20) ans++;
		if (count60.size() > 60) ans++;

		if (curSecond == requestTime[i]) {
			curCount++;
			if (curCount > 3) ans++;
		} else {
			curCount = 1;
			curSecond = requestTime[i];
		}
	}

	return ans;
}

int longestSubstring(string s) {
	unordered_map<char, int> map;
	int ans = 0;

	for (int i = 0, j = 0; i < s.length(); i++) {
		if (map.find(s[i]) != map::end) {
			j = map.at(s[i]);
		}

		if (i - j > ans) ans = i - j;  
		
		map.insert({s[i], i});
	}	

	return ans;
}


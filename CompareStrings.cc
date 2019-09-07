#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

int value(string s) {
	unordered_map<char, int> map;
	char lowest_char = s[0];

	for (int i = 0; i < s.length(); i++) {
		char token = s[i];

		if (token < lowest_char) lowest_char = token;

		if (map.count(token)) {
			map[token] = map[token]+1;
		} else {
			map.insert({token, 1});
		}
	}
	
	//cout<<"for "<<s<<" value = "<<map[lowest_char]<<endl;

	return map[lowest_char];
}

vector<int> solution (string a, string b) {
	vector<int> a_values;

	int index = 0;

	//O(N)
	size_t current, previous = 0;
	current = a.find(",");

	while (current != string::npos) {
		string word = a.substr(previous, current - previous);
		previous = current+1;
		current = a.find(",", previous);

		a_values.push_back(value(word));
	}

	string word = a.substr(previous, current - previous);
	a_values.push_back(value(word));

	current = 0;
	previous = 0;

	vector<string> words;

	current = b.find(",");

	while (current != string::npos) {
		string word = b.substr(previous, current - previous);
		previous = current + 1;
		current = b.find(",", previous);
		words.push_back(word);
	}

	words.push_back(b.substr(previous, current - previous));

	vector<int> ans_vector;

	for (string w : words) {

		int val = value(w);

		int ans = 0;

		for (int v : a_values) {
			if (v < val) ans++;
		}

		ans_vector.push_back(ans);
	}

	return ans_vector;
}

int main (int argv, char* argc []) {
	vector<int> result = solution("a,aa,bb,asdf,fdsa", "abca,aaa,a");

	for (int i : result) cout<<i<<endl;
}

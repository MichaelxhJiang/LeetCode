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
	
	return map[lowest_char];
}

vector<int> solution (string a, string b) {
	int freq [11] = {0}; //since max length of each word is 10, there can only be a max of 10 as frequency of lowest character

	int index = 0;

	//O(N)
	size_t current, previous = 0;
	current = a.find(",");

	while (current != string::npos) {
		string word = a.substr(previous, current - previous);
		previous = current+1;
		current = a.find(",", previous);
		
		freq[value(word)]++;
	}

	string word = a.substr(previous, current - previous);
	freq[value(word)]++;

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

	//prefix sum array the frequencies as we need to query for sum of all frequencies lower than given frequency
	for(int i = 1; i < 11; i++) {
		freq[i] += freq[i-1];
	}

	vector<int> ans_vector;

	for (string w : words) {

		int val = value(w);

		ans_vector.push_back(freq[val-1]);
	}

	return ans_vector;
}

int main (int argv, char* argc []) {
	vector<int> result = solution("a,aa,bb,asdf,fdsa", "abca,aaa,a");

	for (int i : result) cout<<i<<endl;
}

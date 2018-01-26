#include<iostream>
#include<vector>
using namespace std;
vector<string> longestWords(vector<string> &dictionary) {
	int longest_size = -1;
	vector<string> result;
	for (int i = 0; i < dictionary.size(); i++) {
		int current_size = dictionary[i].size();
		if (current_size > longest_size) {
			result.clear();
			result.push_back(dictionary[i]);
			longest_size = current_size;
		}
		else if (dictionary[i].size() == longest_size) {
			result.push_back(dictionary[i]);
		}
	}
	return result;
}
int main() {
	vector<string> d;
	d.push_back("dog");
	d.push_back("google");
	d.push_back("facebook");
	d.push_back("internationalization");
	d.push_back("blabla");
	vector<string> result = longestWords(d);
	return 0;
}
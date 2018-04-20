#include <iostream>
#include <unordered_map>

using namespace std;
int lengthOfLongestSubstring(string s) {
    int size = s.size();
    int length = 0;
    int max_length = 0;
    int index = 0;
    int i = 0;
    unordered_map<char,int> m;
    while (i < size && index < size) {
        if (m.count(s[i]) == 0) {
            m[s[i]] = 1;
            length++;
            i++;
        } else {
			index++;
            i = index;
            m.clear();
            length = 0;
        }
		if (max_length < length) {
			max_length = length;
		}
    }
    return max_length;
}
int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
    cout << lengthOfLongestSubstring("bbbbb") << endl;
    cout << lengthOfLongestSubstring("pwwkew") << endl;
	cout << lengthOfLongestSubstring("dvdf") << endl;
	system("pause");
    return 0;
}
#include <iostream>
using namespace std;

bool isPalindromic(string s) {
    int size = s.size();
    for (int i = 0; i < (size + 1) / 2; i++) {
        if (s[i] != s[size-i-1]) {
            return false;
        }
    }
    return true;
}

string longestPalindrome(string s) {
    int index = 0;
    int max_length = 0;
    int size = s.size();
    string result = "";
    while (index < size) {
        char toFind = s[index];
        for (int i = size-1; i > index; i--) {
            if (s[i] == toFind) {
                string sub_str = s.substr(index, i-index+1);
                if (sub_str.size() > max_length && isPalindromic(sub_str)) {
                    max_length = sub_str.size();
                    result = sub_str;
                }
            }
        }
        index++;
    }
    if (result == "") {
        result = s[0];
    }
    return result;
}

int main() {
    cout << longestPalindrome("babad") << endl;
    cout << longestPalindrome("cbbd") << endl;
    cout << longestPalindrome("abcda") << endl;
    return 0;
}
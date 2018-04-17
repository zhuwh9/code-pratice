#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0) {
        return "";
    }
    string result = "";
    int length = 10000;
    for (int i = 0; i < strs.size(); i++) {
        if (strs[i].size() < length) {
            length = strs[i].size();
        }
    }
    for (int i = 0; i < length; i++) {
        char s = strs[0][i];
        bool flag = true;
        for (int j = 1; j < strs.size(); j++) {
            if (s != strs[j][i]) {
                flag = false;
            }
        }
        if (flag) {
            result += s;
        } else {
            break;
        }
    }
    return result;
}

int main() {
    string a, b, c;
    a = "flower";
    b = "flow";
    c = "flight";
    vector<string> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    cout << longestCommonPrefix(v) << endl;
    return 0;
}

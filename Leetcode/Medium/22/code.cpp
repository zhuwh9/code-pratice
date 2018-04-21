#include <iostream>
#include <string>
#include <vector>

using namespace std;

void generateRecurisve(int left, int right, string temp, vector<string> &result) {
    if (left > right) {
        return;
    }
    if (left == 0 && right == 0) {
        result.push_back(temp);
    } else {
        if (left > 0) {
            generateRecurisve(left-1,right,temp+'(', result);
        }
        if (right > 0) {
            generateRecurisve(left, right-1, temp+')', result);
        }
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    generateRecurisve(n, n, "", result);
    return result;
}

int main() {
    vector<string> result = generateParenthesis(3);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string convert(string s, int numRows) {
    int size = s.size();
    if (size == 0 || numRows == 1) {
        return s;
    }
    int numCols = (size / (2 * numRows - 2) + 1) * (numRows - 1);
    vector< vector<char> > zigzag(numRows, vector<char>(numCols));
    int col = 0, idx = 0;
    bool outOfBound = false;
    while (true) {
        int i;
        for (i = 0; i < numRows; ++i) {
            if (idx >= size) {
                outOfBound = true;
                break;
            }
            zigzag[i][col] = s[idx];
            idx++;
        }
        if (outOfBound) {
            break;
        }
        i -= 2;
        ++col;
        for (; i > 0; --i, ++col) {
            if (idx >= size) {
                outOfBound = true;
                break;
            }
            zigzag[i][col] = s[idx];
            idx++;
        }
        if (outOfBound) {
            break;
        }
    }
    string result = "";
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (zigzag[i][j] != '\0') {
                result += zigzag[i][j];
            }
        }
    }
    return result;
}

int main() {
    string s1("PAYPALISHIRING");
    string s2("PAYPALISHIRING");
    string s3("");
    cout << convert(s1, 3) << endl;
    cout << convert(s2, 4) << endl;
    cout << convert(s3, 1) << endl;
    return 0;
}
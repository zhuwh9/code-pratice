#include <iostream>
#include <vector>

using namespace std;

void swapArray(vector<int> &array, int first, int second) {
    int temp = array[first];
    array[first] = array[second];
    array[second] = temp;
}
void reOrderArray(vector<int> &array) {
    vector<int> oddArray;
    vector<int> evenArray;
    for (int i = 0; i < array.size(); i++) {
        if (array[i] % 2 == 0) evenArray.push_back(array[i]);
        else oddArray.push_back(array[i]);
    }
    int i;
    for (i = 0; i < oddArray.size(); i++) array[i] = oddArray[i];
    for (; i < oddArray.size()+evenArray.size(); i++) array[i] = evenArray[i-oddArray.size()];
}
int main() {
    vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    test.push_back(5);
    reOrderArray(test);
    for (int i = 0; i < test.size(); i++) {
        cout << test[i] << " ";
    }
    cout << endl;
    return 0;
}

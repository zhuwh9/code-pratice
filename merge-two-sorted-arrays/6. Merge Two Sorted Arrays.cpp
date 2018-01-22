#include<iostream>
#include<vector>
using namespace std;
vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
	// write your code here
	int length_a = A.size();
	int length_b = B.size();
	vector<int> result;
	int pos_a = 0;
	int pos_b = 0;
	bool isFull_a = false;
	bool isFull_b = false;
	while (1) {
		if (A.at(pos_a) < B.at(pos_b)) {
			if (isFull_a == false) {
				result.push_back(A.at(pos_a));
				pos_a += 1;
				if (pos_a == length_a) {
					isFull_a = true;
					pos_a -= 1;
				}
			}
			else {//all elements in A already added into result
				if (isFull_b == false) {
					result.push_back(B.at(pos_b));
					pos_b += 1;
					if (pos_b == length_b) {
						isFull_b = true;
						pos_b -= 1;
					}
				}
				else {//all elements in B already added into result
					break;
				}
			}
		}
		else if (A.at(pos_a) >= B.at(pos_b)) {
			if (isFull_b == false) {
				result.push_back(B.at(pos_b));
				pos_b += 1;
				if (pos_b == length_b) {
					isFull_b = true;
					pos_b -= 1;
				}
			}
			else {//all elements in B already added into result
				if (isFull_a == false) {
					result.push_back(A.at(pos_a));
					pos_a += 1;
					if (pos_a == length_a) {
						isFull_a = true;
						pos_a -= 1;
					}
				}
				else {//all elements in A already added into result
					break;
				}
			}
		}
	}
	return result;
}
int main() {
	vector<int> a,b;
	a.push_back(1);a.push_back(2);a.push_back(3);a.push_back(4);
	b.push_back(2);b.push_back(4);b.push_back(5);b.push_back(6);
	vector<int> result;
	result = mergeSortedArray(a, b);
	for (int i = 0; i < result.size(); i++) {
		cout << result.at(i) << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

#include<iostream>
#include<vector>
using namespace std;
int removeElement(vector<int> &A, int elem) {
	vector<int>::iterator itr = A.begin();
	while (itr != A.end()) {
		if (*itr == elem) {
			itr = A.erase(itr);
		}
		else {
			itr++;
		}
	}
	return A.size();
}
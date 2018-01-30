#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// quick way
long long permutationIndex(vector<int> &A) {
	vector<int> a;
	int len = A.size();
	vector<int> cnt(len, 0);
	cnt[len - 1] = 0;
	a.push_back(A[len - 1]);
	for (int i = len - 2;i >= 0; i--) {
		vector<int>::iterator itr = lower_bound(a.begin(), a.end(), A[i]);
		cnt[i] = itr - a.begin();
		a.insert(itr, A[i]);
	}
	long long ans = 1, fac = 1, c = 1;
	for (int i = len - 2; i >= 0; i--) {
		fac *= c;
		c++;
		ans += fac*cnt[i];
	}
	return ans;
}
//// slow way
//long long permutationIndex(vector<int> &A) {
//	vector<int> permu(A.begin(), A.end());
//	sort(permu.begin(), permu.end());
//	int cnt = 0;
//	do {
//		int i;
//		for (i = 0; i < A.size(); ++i) {
//			if (A[i] != permu[i]) {
//				break;
//			}
//		}
//		++cnt;
//		if (i >= A.size()) {
//			break;
//		}
//	} while (next_permutation(permu.begin(), permu.end()));
//	return cnt;
//}
int main() {
	vector<int> t;
	t.push_back(1);
	t.push_back(2);
	t.push_back(4);
	cout << permutationIndex(t) << endl;
	system("pause");
	return 0;
}
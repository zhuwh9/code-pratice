#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int minimumTotal(vector<vector<int> > &triangle) {
	// write your code here
	if (triangle.size() == 0)
		return 0;

	vector<int> f(triangle[triangle.size() - 1].size());//to reserve last level min way value

	f[0] = triangle[0][0];
	for (int i = 1; i < triangle.size(); i++) {
		for (int j = triangle[i].size() - 1; j >= 0; j--) {
			if (j == 0) {//only one min way
				f[j] = f[j] + triangle[i][j];
			}
			else if (j == triangle[i].size() - 1) {//only one min way
				f[j] = f[j - 1] + triangle[i][j];
			}
			else {//find last level adjacent min way
				f[j] = min(f[j - 1], f[j]) + triangle[i][j];
			}
		}
	}
	int ret = INT_MAX;
	for (int i = 0; i < f.size(); i++)
		ret = min(ret, f[i]);
	return ret;
}
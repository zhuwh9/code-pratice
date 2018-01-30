#include<iostream>
using namespace std;
class Solution {
	/**
	* @return: The same instance of this class every time
	*/
private:
	static Solution * p;
public:
	Solution() {}
	static Solution * getInstance() {
		if (p == NULL) {
			p = new Solution();
		}
		else {
			return p;
		}
	}
};
Solution * Solution::p = NULL;
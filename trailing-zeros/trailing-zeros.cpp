#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;
/**
* 本题解题思路是阶乘中对1~n分解因式
* 因为2的数量肯定比5多，所以5的数量就是
* 10的数量，也就是末位0的个数
*/
long long trailingZeros(long n) {
	long long count = 0;
	for (int i = 1; pow(5, i) <= n; i++) {
		count += n / (long)pow(5, i);//注意强制类型转换
	}
	return count;
}
//int main() {
//	long long n = 105;
//	cout << trailingZeros(n) << endl;
//	system("pause");
//	return 0;
//}
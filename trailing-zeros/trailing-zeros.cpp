#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;
/**
* �������˼·�ǽ׳��ж�1~n�ֽ���ʽ
* ��Ϊ2�������϶���5�࣬����5����������
* 10��������Ҳ����ĩλ0�ĸ���
*/
long long trailingZeros(long n) {
	long long count = 0;
	for (int i = 1; pow(5, i) <= n; i++) {
		count += n / (long)pow(5, i);//ע��ǿ������ת��
	}
	return count;
}
//int main() {
//	long long n = 105;
//	cout << trailingZeros(n) << endl;
//	system("pause");
//	return 0;
//}
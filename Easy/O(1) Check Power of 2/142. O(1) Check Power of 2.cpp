#include<iostream>
using namespace std;
// O(log(n)) time
//bool checkPowerOf2(int n) {
//	if (n <= 0) {
//		return false;
//	}
//    while (1) {
//		if (n > 1) {
//			if (n % 2 != 0) {
//				return false;
//			}
//			else if (n % 2 == 0) {
//				n /= 2;
//			}
//		}
//        else if (n == 1) {
//            return true;
//        }
//    }
//    return false;
//}

// O(1) time
//bool checkPowerOf2(int n) {
//	if (n <= 0) {
//		return false;
//	}
//	else {
//		return (n & (n - 1)) == 0 ? true : false;
//	}
//}

// O(32) time
bool checkPowerOf2(int n) {
	if (n <= 0) {
		return false;
	}
	else {
		int count = 0;
		while (n != 0) {
			count += n & 0x01;
			n = n >> 1;
		}
		if (count == 1) {
			return true;
		}
		else {
			return false;
		}
	}
}
int main() {
    int n = 5;
    cout << checkPowerOf2(n) << endl;
	system("pause");
    return 0;
}
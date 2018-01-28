# 141. O(1) Check Power of 2

## Description

Using O(*1*) time to check whether an integer *n* is a power of `2`.

## Example

For `n=4`, return `true`;

For `n=5`, return `false`;

## Challenge

O(1) time

## Analysis

**简单做法**

循环除以2，如果余数不为0，则返回false，否则返回true。

```c++
bool checkPowerOf2(int n) {
	if (n <= 0) {
		return false;
	}
    while (1) {
		if (n > 1) {
			if (n % 2 != 0) {
				return false;
			}
			else if (n % 2 == 0) {
				n /= 2;
			}
		}
		else if (n == 1) {
            return true;
        }
    }
    return false;
}
```



**O(1)做法**

n和n-1在二进制表示下，没有一位是相同的，因此(n & (n-1))结果为0.

```c++
bool checkPowerOf2(int n) {
	if (n <= 0) {
		return false;
	}
	else {
		return (n & (n - 1)) == 0 ? true : false;
	}
}
```



**O(32)做法**

二的倍数在二进制表示下，只有1个位为1，其余所有位为0.

```c++
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
```


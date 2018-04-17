# 13. strStr

## Description

For a given source string and a target string, you should output the **first**index(from 0) of target string in source string.

If target does not exist in source, just return `-1`.

## Clarification

Do I need to implement KMP Algorithm in a real interview?

- Not necessary. When you meet this problem in a real interview, the interviewer may just want to test your basic implementation ability. But make sure you confirm with the interviewer first.

## Example

If source = `"source"` and target = `"target"`, return `-1`.

If source = `"abcdabcdefg"` and target = `"bcd"`, return `1`.

## Analysis

### 1. Naïve Solution

顺序以每个主字符串的字符为首字符，扫描长度为target串长度的子串，如果全部字符都相同，返回主串字符在数组中的下标。

*注意：比较坑爹的点在于如果target串为空串，返回0（空串一定是子串，且第一个字符就能匹配），如果主串或target串任一个是NULL，返回-1（空串和NULL有啥区别...）*

### 2. KMP Algorithm

这个方法是考虑到一些target串中的先验知识进行加速顺序移动的偏移量。

#### KMP算法描述

http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html

#### KMP算法实现

http://blog.csdn.net/a1b2c3d4123456/article/details/50506454
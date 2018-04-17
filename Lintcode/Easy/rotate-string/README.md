# 8. Rotate String

## Description

Given a string and an offset, rotate string by offset. (rotate from left to right)

## Example

Given `"abcdefg"`.

```
offset=0 => "abcdefg"
offset=1 => "gabcdef"
offset=2 => "fgabcde"
offset=3 => "efgabcd"
```

## 分析

利用链表循环将末尾元素pop，然后将这个元素push_front就可以。
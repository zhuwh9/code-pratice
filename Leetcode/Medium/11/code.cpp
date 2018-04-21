#include <iostream>
#include <vector>

using namespace std;

// two pointers
int maxArea(vector<int>& height) {
    int size = height.size();
    int l_p = 0, r_p = size - 1;
    int max_area = 0;
    while (l_p != r_p) {
        int w = height[l_p] > height[r_p] ? height[r_p] : height[l_p];
        int area = w * (r_p - l_p);
        if (area > max_area) {
            max_area = area;
        }
        if (height[l_p] < height[r_p]) {
            l_p++;
        } else {
            r_p--;
        }
    }
    return max_area;
}

// to slow
int maxArea(vector<int>& height) {
    int index = 0;
    int max_area = 0;
    int area = 0;
    int size = height.size();
    while (index < size) {
        for (int i = index + 1; i < size; i++) {
            int h = height[index] > height[i] ? height[i] : height[index];
            area = (i - index) * h;
            if (area > max_area) {
                max_area = area;
            }
        }
        index++;
    }
    return max_area;
}
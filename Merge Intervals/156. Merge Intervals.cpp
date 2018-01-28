#include<iostream>
#include<vector>
using namespace std;
class Interval {
public:
	int start, end;
	Interval(int start, int end) {
		this->start = start;
		this->end = end;
	}
};
void swap(vector<Interval> &intervals, int i, int j) {
	int temp_start = intervals[i].start;
	int temp_end = intervals[i].end;
	intervals[i].start = intervals[j].start;
	intervals[i].end = intervals[j].end;
	intervals[j].start = temp_start;
	intervals[j].end = temp_end;
}
void sortIntervals(vector<Interval> &intervals, int left, int right) {
	if (left < right) {
		Interval pivot = intervals[left];
		int i = left + 1, j = right;
		while (i <= j) {
			while (i <= j && intervals[i].end <= pivot.end) {
				i++;
			}
			while (i <= j && intervals[j].end > pivot.end) {
				j--;
			}
			if (i <= j) {
				swap(intervals, i, j);
				i++;
				j--;
			}
		}
		swap(intervals, left, j);
		sortIntervals(intervals, left, j - 1);
		sortIntervals(intervals, j + 1, right);
	}
}
vector<Interval> merge(vector<Interval> &intervals) {
	sortIntervals(intervals, 0, intervals.size() - 1);

	if (intervals.size() == 0 || intervals.size() == 1) {
		return intervals;
	}
	else {
		int offset = 0;
		while (1) {
			if (intervals.size() <= 1) {
				break;
			}
			int isOutOfBound = intervals.size() - 2 - offset;
			if (isOutOfBound < 0) {
				break;
			}
			Interval last_one = intervals.at(intervals.size() - 1 - offset);
			Interval last_two = intervals.at(intervals.size() - 2 - offset);

			vector<Interval> temp;
			int toSave = 0;
			while (toSave != offset) {
				temp.push_back(intervals.at(intervals.size() - 1 - toSave));
				toSave++;
			}
			while (toSave > 0) {
				intervals.pop_back();
				toSave--;
			}
			intervals.pop_back();
			intervals.pop_back();

			int s1 = last_one.start;
			int s2 = last_two.start;
			int e1 = last_one.end;
			int e2 = last_two.end;

			// [1[2 2]1]
			if (s1 <= s2 && e2 <= e1) {
				intervals.push_back(last_one);
			}// [2[1 1]2]
			else if (s2 <= s1 && e1 <= e2) {
				intervals.push_back(last_two);
			}// [1[2 1]2]
			else if (s1 <= s2 && s2 <= e1 && e1 <= e2) {
				Interval interval(s1, e2);
				intervals.push_back(interval);
			}// [2[1 2]1]
			else if (s2 <= s1 && s1 <= e2 && e2 <= e1) {
				Interval interval(s2, e1);
				intervals.push_back(interval);
			}
			else {
				// [1 1]space[2 2]
				if (e1 < s2) {
					intervals.push_back(last_one);
					intervals.push_back(last_two);
					offset += 1;
				}// [2 2]space[1 1]
				else if (e2 < s1) {
					intervals.push_back(last_two);
					intervals.push_back(last_one);
					offset += 1;
				}
				else {
					break;
				}
			}
			while (temp.empty() == false) {
				intervals.push_back(temp.back());
				temp.pop_back();
			}
		}
	}
	return intervals;
}
//int main() {
//	vector<Interval> intervals;
//	Interval temp(1, 4);
//	intervals.push_back(temp);
//	temp.start = 0;temp.end = 2;
//	intervals.push_back(temp);
//	temp.start = 3;temp.end = 5;
//	intervals.push_back(temp);
//	vector<Interval> result = merge(intervals);
//	system("pause");
//	return 0;
//}
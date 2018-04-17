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

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
	// make start sequencially
	intervals.push_back(newInterval);
	for (int i = intervals.size() - 1; i > 0; i--) {
		if (intervals[i].end < intervals[i - 1].end) {
			int temp_start, temp_end;
			temp_start = intervals[i].start;
			intervals[i].start = intervals[i - 1].start;
			intervals[i - 1].start = temp_start;
			temp_end = intervals[i].end;
			intervals[i].end = intervals[i - 1].end;
			intervals[i - 1].end = temp_end;
		}
		else {
			break;
		}
	}
	// start to merge the intervals
	int offset = 0;
	while (1) {
		if (intervals.size() <= 1) {
			break;
		}
		int isOutOfBound = intervals.size() - 2 - offset;
		if (isOutOfBound < 0) {
			break;
		}
		Interval interval1 = intervals.at(intervals.size() - 1 - offset);
		Interval interval2 = intervals.at(intervals.size() - 2 - offset);
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
		//[1[2 2]1]
		if (interval1.start <= interval2.start &&
			interval2.end <= interval1.end) {
			Interval interval(interval1.start, interval1.end);
			intervals.push_back(interval);
		}//[1[2 1]2]
		else if (interval1.start <= interval2.start &&
			interval2.start <= interval1.end && 
			interval1.end <= interval2.end) {
			Interval interval(interval1.start, interval2.end);
			intervals.push_back(interval);
		}//[2[1 2]1]
		else if (interval2.start <= interval1.start && 
			interval1.start <= interval2.end &&
			interval2.end <= interval1.end){
			Interval interval(interval2.start, interval1.end);
			intervals.push_back(interval);
		}//[2[1 1]2]
		else if (interval2.start <= interval1.start &&
			interval1.start <= interval1.end &&
			interval1.end <= interval2.end) {
			Interval interval(interval2.start, interval2.end);
			intervals.push_back(interval);
		}//no cross area
		else {
			//[11]space[22]
			if (interval1.end < interval2.start) {
				intervals.push_back(interval1);
				intervals.push_back(interval2);
				offset += 1;
			}//[22]space[11]
			else if (interval2.end < interval1.start) {
				intervals.push_back(interval2);
				intervals.push_back(interval1);
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
	return intervals;
}
int main() {
	vector<Interval> intervals;
	Interval interval1(1, 5);
	Interval interval2(7, 8);
	Interval interval3(10, 13);
	intervals.push_back(interval1);
	intervals.push_back(interval2);
	intervals.push_back(interval3);
	Interval interval(6, 6);
	vector<Interval> result = insert(intervals, interval);
	int a = 1;
	system("pause");
	return 0;
}
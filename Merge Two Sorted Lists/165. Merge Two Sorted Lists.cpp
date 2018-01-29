#include<iostream>
#include<vector>
#include<string>
using namespace std;
class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};
void swap(vector<int> &result, int i, int j) {
	int temp = result[i];
	result[i] = result[j];
	result[j] = temp;
}
void quickSort(vector<int> &result, int left, int right) {
	if (left < right) {
		int pivot = result[left];
		int i = left + 1, j = right;
		while (i <= j) {
			while (i <= j && result[i] <= pivot) {
				i++;
			}
			while (i <= j && result[j] > pivot) {
				j--;
			}
			if (i <= j) {
				swap(result, i, j);
				i++;
				j--;
			}
		}
		swap(result, left, j);
		quickSort(result, left, j - 1);
		quickSort(result, j + 1, right);
	}
}
ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
	vector<int> temp;
	while (l1 != NULL) {
		temp.push_back(l1->val);
		l1 = l1->next;
	}
	while (l2 != NULL) {
		temp.push_back(l2->val);
		l2 = l2->next;
	}
	quickSort(temp, 0, temp.size() - 1);
	if (temp.size() == 0) {
		return NULL;
	}
	else {
		ListNode * result = new ListNode(temp[0]);
		ListNode * t = result;
		for (int i = 1; i < temp.size(); i++) {
			result->next = new ListNode(temp[i]);
			result = result->next;
		}
		return t;
	}
}
int main() {
	ListNode * l1 = NULL;
	ListNode * l2 = new ListNode(0);
	ListNode * l2_head = l2;
	l2->next = new ListNode(3);
	l2 = l2->next;
	l2->next = new ListNode(3);
	l2 = l2->next;
	ListNode * result = mergeTwoLists(l1, l2_head);
}
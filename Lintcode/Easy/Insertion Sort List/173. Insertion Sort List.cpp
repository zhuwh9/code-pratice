#include<iostream>
#include<vector>
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
ListNode * insertionSortList(ListNode * head) {
	vector<int> t;
	while (head != NULL) {
		t.push_back(head->val);
		head = head->next;
	}
	for (int i = 1; i < t.size(); i++) {
		int pivot = t[i];
		int j;
		for (j = i; j > 0 && pivot < t[j - 1]; j--) {
			t[j] = t[j - 1];
		}
		t[j] = pivot;
	}
	ListNode * result = new ListNode(t[0]);
	ListNode * result_head = result;
	for (int i = 1; i < t.size(); i++) {
		result->next = new ListNode(t[i]);
		result = result->next;
	}
	return result_head;
}
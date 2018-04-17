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
// use vector
ListNode * nthToLast(ListNode * head, int n) {
	if (head == NULL || n == 0) {
		return NULL;
	}
	vector<int> t;
	while (head != NULL) {
		t.push_back(head->val);
		head = head->next;
	}
	if (t.size() < n) {
		return NULL;
	}
	ListNode * t1 = new ListNode(t[t.size()-n]);
	ListNode * result = t1;
	for (int i = t.size() - n; i < t.size(); i++) {
		t1->next = new ListNode(t[i]);
		t1 = t1->next;
	}
	return result;
}
// use two pointer
ListNode * nthToLast(ListNode * head, int n) {
	if (head == NULL || n == 0) {
		return NULL;
	}
	ListNode * l1 = head;
	ListNode * l2 = head;
	while (--n) {
		if (l1->next == NULL) {
			return NULL;
		}
		else {
			l1 = l1->next;
		}
	}
	while (l1->next != NULL) {
		l1 = l1->next;
		l2 = l2->next;
	}
	return l2;
}
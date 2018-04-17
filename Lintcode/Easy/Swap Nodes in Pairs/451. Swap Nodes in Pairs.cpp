#include<iostream>
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
ListNode * swapPairs(ListNode * head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	else {
		ListNode * pointer = head;
		int temp = 0;
		while (pointer != NULL && pointer->next != NULL) {
			temp = pointer->val;
			pointer->val = pointer->next->val;
			pointer->next->val = temp;
			pointer = pointer->next->next;
		}
		return head;
	}
}
ListNode * swapPairs(ListNode * head) {
	if (head == NULL) {
		return NULL;
	}
	ListNode * helper = new ListNode(0);
	helper->next = head;
	ListNode * pre = helper;
	ListNode * cur = head;
	while (cur != NULL && cur->next != NULL) {
		ListNode * next = cur->next->next;
		cur->next->next = cur;
		pre->next = cur->next;
		if (next != NULL && next->next != NULL) {
			cur->next = next->next;
		}
		else {
			cur->next = next;
		}
		pre = cur;
		cur = next;
	}
	return helper->next;
}
int main() {
	ListNode * t = new ListNode(1);
	ListNode * head = t;
	t->next = new ListNode(2);
	t = t->next;
	t->next = new ListNode(3);
	t = t->next;
	t->next = new ListNode(4);
	t = t->next;
	t->next = new ListNode(5);
	t = t->next;
	t->next = new ListNode(6);
	ListNode * result = swapPairs(head);
	while (result != NULL) {
		cout << result->val << " ";
		result = result->next;
	}
	system("pause");
	return 0;
}
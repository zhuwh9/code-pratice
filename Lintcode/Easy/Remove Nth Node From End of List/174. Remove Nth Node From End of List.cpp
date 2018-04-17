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
ListNode * removeNthFromEnd(ListNode * head, int n) {
	if (head == NULL || n == 0) {
		return NULL;
	}
	ListNode * l1 = head;
	ListNode * l2 = head;
	while (n--) {
		l1 = l1->next;
	}
	if (l1 == NULL) {
		return head->next;
	}
	while (l1->next != NULL) {
		l1 = l1->next;
		l2 = l2->next;
	}
	l2->next = l2->next->next;
	return head;
}
int main() {
	ListNode * t = new ListNode(1);
	ListNode * t_head = t;
	t->next = new ListNode(2);
	t = t->next;
	t->next = new ListNode(3);
	t = t->next;
	t->next = new ListNode(4);
	t = t->next;
	t->next = new ListNode(5);
	removeNthFromEnd(t_head, 2);
	system("pause");
	return 0;
}
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
ListNode * partition(ListNode * head, int x) {
	if (head == NULL) {
		return head;
	}
	ListNode * smaller = NULL;
	ListNode * larger = NULL;
	ListNode * smallerHead = NULL;
	ListNode * largerHead = NULL;
	bool isSmallerHead = true;
	bool isLargerHead = true;
	ListNode * temp = head;
	while (temp != NULL) {
		if (temp->val < x) {
			if (isSmallerHead) {
				smaller = new ListNode(temp->val);
				smallerHead = smaller;
				isSmallerHead = false;
			}
			else {
				ListNode * t = new ListNode(temp->val);
				t->next = smaller->next;
				smaller->next = t;
				smaller = smaller->next;
			}
		}
		if (temp->val >= x) {
			if (isLargerHead) {
				larger = new ListNode(temp->val);
				largerHead = larger;
				isLargerHead = false;
			}
			else {
				ListNode * t = new ListNode(temp->val);
				t->next = larger->next;
				larger->next = t;
				larger = larger->next;
			}
		}
		temp = temp->next;
	}
	if (smaller == NULL) {
		return largerHead;
	}
	smaller->next = largerHead;
	return smallerHead;
}
int main() {
	ListNode* t1 = new ListNode(3);
	ListNode* head = t1;
	t1->next = new ListNode(3);
	t1 = t1->next;
	t1->next = new ListNode(1);
	t1 = t1->next;
	t1->next = new ListNode(2);
	t1 = t1->next;
	t1->next = new ListNode(4);
	t1 = t1->next;
	ListNode* result = partition(head, 3);
	system("pause");
	return 0;
}
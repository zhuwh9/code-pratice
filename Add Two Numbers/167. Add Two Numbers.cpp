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
ListNode * addLists(ListNode * l1, ListNode * l2) {
	int carrier = 0;
	int remainder = 0;
	int sum = 0;
	ListNode * result = new ListNode(carrier);
	ListNode * result_head = result;
	while (1) {
		sum = 0;
		if (l1 == NULL && l2 == NULL) {
			break;
		}
		else {
			if (l1 != NULL && l2 != NULL) {
				sum = l1->val + l2->val + carrier;
				l1 = l1->next;
				l2 = l2->next;
			}
			else if (l1 == NULL && l2 != NULL) {
				sum = l2->val + carrier;
				l2 = l2->next;
			}
			else if (l1 != NULL && l2 == NULL) {
				sum = l1->val + carrier;
				l1 = l1->next;
			}
			remainder = sum % 10;
			result->next = new ListNode(remainder);
			result = result->next;
			carrier = sum / 10;
		}
	}
	if (carrier != 0) {
		result->next = new ListNode(carrier);
	}
	return result_head->next;
}
int main() {
	ListNode * l1 = new ListNode(1);
	ListNode * l1_head = l1;
	l1->next = new ListNode(1);
	l1 = l1->next;
	l1->next = new ListNode(1);
	ListNode * l2 = new ListNode(9);
	ListNode * l2_head = l2;
	l2->next = new ListNode(8);
	l2 = l2->next;
	l2->next = new ListNode(8);
	ListNode * result = addLists(l1_head, l2_head);
	system("pause");
	return 0;
}
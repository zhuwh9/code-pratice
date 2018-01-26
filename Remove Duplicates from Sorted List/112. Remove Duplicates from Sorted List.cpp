#include<iostream>
#include<vector>
using namespace std;
class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};
ListNode * deleteDuplicates(ListNode * head) {
	if (head == NULL) {
		return NULL;
	}
	else {
		ListNode* temp = head;
		int current = temp->val;
		while (temp->next != NULL) {
			if (current == temp->next->val) {
				temp->next = temp->next->next;
			}
			else {
				current = temp->next->val;
				temp = temp->next;
			}
		}
		return head;
	}
}
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
void deleteNode(ListNode * node) {
	node->val = node->next->val;
	node->next = node->next->next;
}
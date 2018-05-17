#include<iostream>
#include<stack>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* ReverseList(ListNode* pHead) {
	stack<int> s;
	if (pHead == NULL) {
		return NULL;
	}
	while (pHead != NULL) {
		s.push(pHead->val);
		pHead = pHead->next;
	}
	ListNode* t = new ListNode(0);
	ListNode* res = t;
	while (s.empty() == false) {
		t->next = new ListNode(s.top());
		s.pop();
		t = t->next;
	}
	return res->next;
}

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* l = new ListNode(0);
    ListNode* head = l;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            l->next = new ListNode(l1->val);
            l1 = l1->next;
        } else {
            l->next = new ListNode(l2->val);
            l2 = l2->next;
        }
        l = l->next;
    }  
    while (l1 != NULL) {
        l->next = new ListNode(l1->val);
        l = l->next;
        l1 = l1->next;
    }
    while (l2 != NULL) {
        l->next = new ListNode(l2->val);
		l = l->next;
        l2 = l2->next;
    }
    return head->next;
}

int main() {
	ListNode* l1 = new ListNode(-9);
	l1->next = new ListNode(3);
	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(7);
	ListNode* l3 = mergeTwoLists(l1, l2);
	while (l3 != NULL) {
		cout << l3->val << " ";
		l3 = l3->next;
	}
	system("pause");
	return 0;
}
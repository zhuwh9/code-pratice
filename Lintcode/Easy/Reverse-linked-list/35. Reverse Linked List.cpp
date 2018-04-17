#include<iostream>
#include<vector>
#include<list>
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

ListNode * reverse(ListNode * head) {
	// write your code here
	if (head == NULL) {
		return NULL;
	}
	vector<int> t;
	while (1) {
		t.push_back(head->val);
		head = head->next;
		if (head == NULL) {
			break;
		}
	}
	ListNode* temp = new ListNode(t.back());
	ListNode* result = temp;
	while (t.empty() == false) {
		t.pop_back();
		if (t.empty()) {
			break;
		}
		temp->next = new ListNode(t.back());
		temp = temp->next;
	}
	return result;
}
int main() {
	ListNode* t = new ListNode(1);
	ListNode* first = t;
	t->next = new ListNode(2);
	t = t->next;
	t->next = new ListNode(3);
	ListNode* result = reverse(first);
	while (1) {
		cout << result->val << " ";
		result = result->next;
		if (result == NULL) {
			break;
		}
	}
	system("pause");
	return 0;
}
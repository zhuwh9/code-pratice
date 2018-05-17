#include <iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	if (pListHead == NULL || k <= 0) {//链表为空或者K的取值范围有问题
		return NULL;
	}
    ListNode* n1 = pListHead;
    ListNode* n2 = pListHead;
    while (k > 0 && n2 != NULL) {
        n2 = n2->next;
        k--;
    }
	if (k > 0 && n2 == NULL) {//长度大于数组
		return NULL;
	}
    while (n2 != NULL) {
        n1 = n1->next;
        n2 = n2->next;
    }
    return n1;
}
int main() {
    ListNode* head = new ListNode(1);
    ListNode* node = head;
    for (int i = 2; i <= 10; i++) {
        head->next = new ListNode(i);
        head = head->next;
    }
    ListNode* res = FindKthToTail(node, 5);
    while (res != NULL) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
	system("pause");
    return 0;
}

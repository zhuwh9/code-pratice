/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* l1 = pHead1;
        ListNode* l2 = pHead2;
        while (l1 != l2) {
            l1 = l1 == NULL ? pHead2 : l1->next;
            l2 = l2 == NULL ? pHead1 : l2->next;
        }
        return l1;
    }
};

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* toEnd = head;
    ListNode* beforeTarget = head;
    bool isHead = false;
    while (n > 0) {
        if (toEnd->next == NULL) {
            // last element
            isHead = true;
            break;
        } else {
            toEnd = toEnd->next;
        }
        n--;
    }
    if (isHead) {
        return head->next;
    }
    while (toEnd->next != NULL) {
        toEnd = toEnd->next;
        beforeTarget = beforeTarget->next;
    }
    beforeTarget->next = beforeTarget->next->next;
    return head;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    p->next = new ListNode(2);
    ListNode* result = removeNthFromEnd(head, 1);
    while (result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
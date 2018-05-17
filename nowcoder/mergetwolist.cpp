    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == NULL && pHead2 == NULL) {
            return NULL;
        } else if (pHead1 == NULL && pHead2 != NULL) {
            return pHead2;
        } else if (pHead1 != NULL && pHead2 == NULL) {
            return pHead1;
        } else {//pHead1 != NULL && pHead2 != NULL
            ListNode * res = new ListNode(0);
            ListNode * t = res;
            int val1 = 0, val2 = 0, les = 0;
            while (pHead1 != NULL && pHead2 != NULL) {
                val1 = pHead1->val;
                val2 = pHead2->val;
                if (val1 <= val2) {
                    les = val1;
                    pHead1 = pHead1->next;
                } else {
                    les = val2;
                    pHead2 = pHead2->next;
                }
                t->next = new ListNode(les);
                t = t->next;
            }
            if (pHead1 != NULL) {
                t->next = pHead1;
            }
            if (pHead2 != NULL) {
                t->next = pHead2;
            }
            return res->next;
        }
    }

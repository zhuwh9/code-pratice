#include <iostream>

using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {
	}
};

RandomListNode* Clone(RandomListNode* pHead) {
	if (pHead == NULL) return NULL;
	RandomListNode* node = pHead;
	while (node != NULL) {
		RandomListNode* newNode = new RandomListNode(node->label);
		newNode->next = node->next;
		node->next = newNode;
		node = newNode->next;
	}
	node = pHead;
	while (node != NULL) {
		RandomListNode* t = node->next;
		if (node->random) {
			t->random = node->random->next;
		}
		node = t->next;
	}
	RandomListNode* pCloneHead = pHead->next;
	RandomListNode* tmp;
	node = pHead;
	while (node->next != NULL) {
		tmp = node->next;
		node->next = tmp->next;
		node = tmp;
	}
	return pCloneHead;
}

int main() {
	RandomListNode* root = new RandomListNode(1);
	root->next = new RandomListNode(2);
	root->next->next = new RandomListNode(3);
	root->next->random = root->next->next;
	root->random = root->next;
	root->next->next->random = NULL;
	RandomListNode* res = Clone(root);
	system("pause");
	return 0;
}

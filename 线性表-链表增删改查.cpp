#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

typedef struct Node LNode;

LNode* createList() {
	LNode* head, * p, * q;
	int x;
	head = (LNode*)malloc(sizeof(LNode));
	p = head;
	while (1) {
		scanf_s("%d", &x);
		if (x == -1) break;
		q = (LNode*)malloc(sizeof(LNode));
		q->data = x;
		p->next = q;
		p = q;
	}
	p->next = nullptr;
	return head;
}

void printList(LNode *head) {
	LNode* p;
	p = head->next;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
}

/*增加结点*/
void addNode(LNode *head, int x) {
	LNode* q, * p;
	p = head;
	q = (LNode*)malloc(sizeof(LNode));
	q->data = x;
	q->next = p->next;
	p->next = q;
}
/*删除结点*/
void deleteNode(LNode* head, int i) {
	LNode* p, * q;
	p = head;
	q = head->next;
	while (i>1) {
		p = p->next;
		q = q->next;
		i--;
	}
	p->next = q->next;
	free(q);
}
/*修改结点*/
void changeNode(LNode* head, int i, int x) {
	LNode* p;
	p = head;
	while (i--) {
		p = p->next;
	}
	p->data = x;
}
/*查找结点*/
void getNode(LNode *head, int i, int *e) {
	LNode* p;
	p = head;
	while (i--) {
		p = p->next;
	}
	*e = p->data;
}
int main() {
	int* e = (int *)malloc(sizeof(int));
	LNode* head;
	head = createList();
	printList(head);
	printf("\n");
	addNode(head, 9);
	printList(head);
	deleteNode(head, 3);
	printf("\n");
	printList(head);
	changeNode(head, 1, 2);
	printf("\n");
	printList(head);
	printf("\n");
	getNode(head, 2, e);
	printf("%d", *e);
}
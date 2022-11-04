#include<stdio.h>
#include<stdlib.h>
typedef int EType;
// ���нṹ��
typedef struct Queue {
	EType data;
	Queue* next;
}Queue;

//ͷβָ��
typedef struct Node{
	Queue* first;
	Queue* rear;
}Node;
//��ʼ������
void initQueue(Queue* q, Node* node);
//��������
void createQueue(Node* node);
//��ȡ��ͷԪ��
void getQueue(Node* node);
//��β����Ԫ��
void insertQueue(Node* node, EType x);
//������ͷԪ��
void popQueue(Node* node);
//��ӡ����
void printQueue(Node* node);
int main() {
	Queue q;
	Node node;
	initQueue(&q, &node);
	createQueue(&node);
	getQueue(&node);
	popQueue(&node);
	getQueue(&node);
	insertQueue(&node, 7);
	printf("\n");
	printQueue(&node);
}
void initQueue(Queue* q, Node* node) {
	q = (Queue*)malloc(sizeof(Queue));
	q->next = NULL;
	node->first = node->rear = q;
}

void createQueue(Node* node) {
	EType x;
	while (1) {
		scanf_s("%d", &x);
		if (x != -1) {
			Queue* p = (Queue*)malloc(sizeof(Queue));
			p->data = x;
			p->next = node->rear->next;
			node->rear->next = p;
		}
		else {
			break;
		}
	}
	Queue* p = node->first;
	while (p->next) {
		p = p->next;
	}
	node->first = p;
}
void getQueue(Node* node) {
	Queue* p = node->first;
	printf("%d", p->data);
}

void insertQueue(Node* node, EType x) {
	Queue* p = (Queue*)malloc(sizeof(Queue));
	p->data = x;
	p->next = node->rear->next;
	node->rear->next = p;
}

void popQueue( Node* node) {
	Queue* p = node->rear;
	while (p->next->next) {
		p = p->next;
	}
	node->first = p;
	node->first->next = NULL;
	free(p->next);
}

void printQueue(Node* node) {
	Queue* p = node->rear->next;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
}
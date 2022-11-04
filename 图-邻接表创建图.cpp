#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<vector>

using namespace std;

#define NUMS 15
/*�������������Ʋ������ظ�*/

//������
typedef struct ArcNode {
	int index; // �������
	struct ArcNode* next; //��һ������
}ArcNode;

//��Ŷ����firstָ��
typedef struct VAnode {
	char name;
	int vertex;
	ArcNode* first; 
}VAnode;

//ͼ
typedef struct Graph {
	VAnode vnums[NUMS];
	int vnum, anum;// �������ͱ���
	char name[NUMS];
}Graph;

//�ҵ�ָ�����������
void findIndex(Graph* g, char c1, char c2, int* v1, int* v2) {
	int i;
	for (i = 0; i < g->vnum; i++) {
		if (c1 == g->vnums[i].name) *v1 = g->vnums[i].vertex;
		if (c2 == g->vnums[i].name) *v2 = g->vnums[i].vertex;
	}
}
//���ȳ�ʼ�����ͼ
void initGraph(Graph* g) {
	int i;
	printf("������ͼ�Ķ�����\n");
	scanf_s("%d", &g->vnum);
	printf("������ͼ�ı���\n");
	scanf_s("%d", &g->anum);
	printf("�����붥������\n");
	getchar();
	for (i = 0; i < g->vnum; i++) {
		scanf_s("%c", &g->name[i]);
		getchar();
	}
}
//����ͼ
void createGraph(Graph* g) {
	int i;
	char v1, v2;
	int v1_i, v2_i;
	int flag;
	printf("��������ͼ������0����������ͼ����1\n");
	scanf_s("%d", &flag);
	getchar();
	for (i = 0; i < g->vnum; i++) {
		g->vnums[i].name = g->name[i];
		g->vnums[i].vertex = i;
		g->vnums[i].first = (ArcNode*)malloc(sizeof(ArcNode));
		g->vnums[i].first->next = NULL;
	}
	//��������Ͷ���֮�����ϵ
	printf("(����ͼ)���a��b�бߣ������룺a b�� ���b��a�бߣ������룺b a\n");
	printf("(����ͼ)���a��b�бߣ������룺a b\n");
	for (i = 0; i < g->anum; i++) {
		scanf_s("%c %c", &v1, 1, &v2, 1);
		getchar();
		findIndex(g, v1, v2, &v1_i, &v2_i);
		ArcNode* p, * q;
		p = g->vnums[v1_i].first;
		while (p ->next != NULL) {
			p = p->next;
		}
		q = (ArcNode*)malloc(sizeof(ArcNode));
		q->index = v2_i;
		q->next = NULL;
		p->next = q;
		if (flag == 0) {
			//����ͼ��Ҫ��������
			p = g->vnums[v2_i].first;
			while (p->next != NULL) {
				p = p->next;
			}
			q = (ArcNode*)malloc(sizeof(ArcNode));
			q->index = v1_i;
			q->next = NULL;
			p->next = q;
		}
	}
	if(flag == 0)
		printf("����ͼ�������\n");
	else
		printf("����ͼ�������\n");
}

void printGraph(Graph* g) {
	int i;
	for (i = 0; i < g->vnum; i++) {
		printf("%c->", g->vnums[i].name);
		ArcNode* p;
		p = g->vnums[i].first->next;
		while (p)
		{
			if (p->next == NULL) printf("%c", g->vnums[p->index].name);
			else printf("%c->", g->vnums[p->index].name);
			p = p->next;
		}
		printf("\n");
	}
}

void dfs(Graph* g) {
	vector<int> visited(g->vnum);
	int i;
	for (i = 0; i < g->vnum; i++) {
		visited[i] = 0;
	}
	stack<ArcNode*> stk;
	stk.push(g->vnums[0].first);
	visited[0] = 1;
	printf("%c", g->vnums[0].name);
	while (!stk.empty()) {
		ArcNode* p;
		p = stk.top()->next;
		int flag = 0;
		while (p) {
			if (visited[p->index] == 0) {
				stk.push(g->vnums[p->index].first);
				flag = 1;
				break;
			}
			if (p->next)
				p = p->next;
			else break;
		}
		if (flag == 0) {
			stk.pop();
			continue;
		}
		if (visited[p->index] == 0) {
			visited[p->index] = 1;
			printf("%c", g->vnums[p->index].name);
		}
	}
}
int main() {
	Graph g;
	initGraph(&g);
	createGraph(&g);
	printGraph(&g);
	printf("��������������\n");
	dfs(&g);
}
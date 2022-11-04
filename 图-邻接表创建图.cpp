#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<vector>

using namespace std;

#define NUMS 15
/*声明：顶点名称不可以重复*/

//边链表
typedef struct ArcNode {
	int index; // 存放索引
	struct ArcNode* next; //下一个顶点
}ArcNode;

//存放顶点和first指针
typedef struct VAnode {
	char name;
	int vertex;
	ArcNode* first; 
}VAnode;

//图
typedef struct Graph {
	VAnode vnums[NUMS];
	int vnum, anum;// 定点数和边数
	char name[NUMS];
}Graph;

//找到指定顶点的索引
void findIndex(Graph* g, char c1, char c2, int* v1, int* v2) {
	int i;
	for (i = 0; i < g->vnum; i++) {
		if (c1 == g->vnums[i].name) *v1 = g->vnums[i].vertex;
		if (c2 == g->vnums[i].name) *v2 = g->vnums[i].vertex;
	}
}
//首先初始化这个图
void initGraph(Graph* g) {
	int i;
	printf("请输入图的顶点数\n");
	scanf_s("%d", &g->vnum);
	printf("请输入图的边数\n");
	scanf_s("%d", &g->anum);
	printf("请输入顶点名称\n");
	getchar();
	for (i = 0; i < g->vnum; i++) {
		scanf_s("%c", &g->name[i]);
		getchar();
	}
}
//创建图
void createGraph(Graph* g) {
	int i;
	char v1, v2;
	int v1_i, v2_i;
	int flag;
	printf("创建无向图请输入0，创建有向图输入1\n");
	scanf_s("%d", &flag);
	getchar();
	for (i = 0; i < g->vnum; i++) {
		g->vnums[i].name = g->name[i];
		g->vnums[i].vertex = i;
		g->vnums[i].first = (ArcNode*)malloc(sizeof(ArcNode));
		g->vnums[i].first->next = NULL;
	}
	//构建顶点和顶点之间的联系
	printf("(有向图)如果a和b有边，即输入：a b， 如果b和a有边，即输入：b a\n");
	printf("(无向图)如果a和b有边，即输入：a b\n");
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
			//无向图需要构建两次
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
		printf("无向图构建完成\n");
	else
		printf("有向图构建完成\n");
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
	printf("深度优先搜索结果\n");
	dfs(&g);
}
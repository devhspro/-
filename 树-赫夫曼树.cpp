#include<stdio.h>
#include<stdlib.h>

//赫夫曼树结点
typedef struct hnode{
	int weight; //权值
	int parent, lchild, rchild;
}HNode, *HTree;

//选择两个权值最小的结点
void selectTwo(HTree *ht, int* s1, int* s2, int n) {
	int i;
	int min = 100;
	for (i = 1; i <= n; i++) {
		if ((*ht)[i].weight <= min && (*ht)[i].parent == 0) {
			min = (*ht)[i].weight;
			*s1 = i;
		}
	}
	min=100;
	for (i = 1; i <= n; i++) {
		if ((*ht)[i].weight <= min && i != *s1 && (*ht)[i].parent == 0) {
			min = (*ht)[i].weight;
			*s2 = i;
		}
	}
}

//构造赫夫曼树
void createHTree(HTree* ht, int n) {
	int i, s1, s2;
	int m = 2 * n - 1;
	*ht = (HTree)malloc((m + 1) * sizeof(HNode));
	for (i = 1; i <= m; i++) {
		(*ht)[i].weight = 0;
		(*ht)[i].parent = 0;
		(*ht)[i].lchild = 0;
		(*ht)[i].rchild = 0;
	}
	for (i = 1; i <= n; i++) {
		scanf_s("%d", &((*ht)[i].weight));
	}
	for (i = n + 1; i <= m; i++) {
		selectTwo(ht, &s1, &s2, n++);
		int newWeight = (*ht)[s1].weight + (*ht)[s2].weight;
		(*ht)[i].weight = newWeight;
		(*ht)[i].lchild = (*ht)[s1].weight;
		(*ht)[i].rchild = (*ht)[s2].weight;
		(*ht)[s1].parent = (*ht)[i].weight;
		(*ht)[s2].parent = (*ht)[i].weight;
	}
}

void PrintHuffmanTree(HTree* ht, int num)//打印树
{
	for (int i = 1; i <= 2*num-1; i++)
	{
		printf("weight:%d  parent:%d childleft:%d  childright:%d\n", (*ht)[i].weight, (*ht)[i].parent, (*ht)[i].lchild, (*ht)[i].rchild);
	}
}
int main() {
	HTree ht;
	createHTree(&ht, 4);
	PrintHuffmanTree(&ht, 4);
}
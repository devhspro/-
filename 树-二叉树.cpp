#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>

using namespace std;

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}Node;

typedef struct {
	Node* root;
}Tree;

void createTree(Tree* t, int value) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = value;
	node->left = NULL;
	node->right = NULL;
	if (t->root == NULL) {
		t->root = node;
	}

	else {
		Node* temp = t->root;
		while (temp != NULL) {
			if (value < temp->data) {
				if (temp->left == NULL) {
					temp->left = node;
					return;
				}
				else {
					temp = temp->left;
				}
			}
			else {
				if (temp->right == NULL) {
					temp->right = node;
					return;
				}
				else {
					temp = temp->right;
				}
			}

		}
	}
}

void preOrder(Node* node) {
	if (node != NULL) {
		printf("%d ", node->data);
		preOrder(node->left);
		preOrder(node->right);
	}
}

void inOrder(Node* node) {
	// ·ÇµÝ¹é
	stack<Node*> stk;
	stk.push(node);
	Node* p = stk.top();
	while (!stk.empty() && p) {
		while (p->left) {
			p = p->left;
			stk.push(p);
		}
		p = stk.top();
		printf("%d ", p->data);
		stk.pop();
		if (p->right) {
			p = p->right;
			stk.push(p);
		}
	}
	/*if (node != NULL) {
		inOrder(node->left);
		printf("%d ", node->data);
		inOrder(node->right);
	}*/
}
	
	

int main() {
	Tree tree;
	tree.root = NULL;
	int arr[7] = {6, 2, 3, 1, 5, 8, 7};
	for (int i = 0; i < 7; i++) {
		createTree(&tree, arr[i]);
	}
	preOrder(tree.root);
	printf("\n");
	inOrder(tree.root);
}
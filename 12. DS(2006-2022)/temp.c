#include <stdio.h>
#include <stdlib.h>
typedef struct TNode{
	int data;
	struct TNode *left, *right;
}TNode;

int Ancestor(TNode *root, int v, int w){
	int a, b, c, d, x, y;
	if (!root) return -1;
	
	if (root->data == v){
		//printf("%d ", root->data);
		return root->data;
	}
	else{
		a = Ancestor(root->left, v, w);
		b = Ancestor(root->right, v, w);
		if (a != -1 || b != -1){
			//printf("%d ", root->data);
			x = root->data;
		}
		else
			x = -1;
	}
	
	if (root->data == w){
		return root->data;
	}
	else{
		c = Ancestor(root->left, v, w);
		d = Ancestor(root->right, v, w);
		if (c != -1 || d != -1){
			//printf("%d ", root->data);
			y = root->data;
		}
		else
			y = -1;
	}
	
	if (x == -1 && y == -1)
		return -1;
	
}

int main(){
	int is;
	TNode *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8, *n9;
	n1 = (TNode*)malloc(sizeof(TNode));
	n2 = (TNode*)malloc(sizeof(TNode));
	n3 = (TNode*)malloc(sizeof(TNode));
	n4 = (TNode*)malloc(sizeof(TNode));
	n5 = (TNode*)malloc(sizeof(TNode));
	n6 = (TNode*)malloc(sizeof(TNode));
	n7 = (TNode*)malloc(sizeof(TNode));
	n8 = (TNode*)malloc(sizeof(TNode));
	n9 = (TNode*)malloc(sizeof(TNode));
	
	n1->data = 40;
	n2->data = 55;
	n3->data = 20;
	n4->data = 50;
	n5->data = 10;
	n6->data = 70;
	n7->data = 30;
	n8->data = 45;
	n9->data = 52;
	
	n4->left = n4->right = n5->left = n5->right = n7->left = n7->right = n8->left = n8->right = n9->left = n9->right = NULL;
	
	n6->left = n8;
	n6->right = n9;
	n3->left = n6;
	n3->right = n7;
	n2->left = n4;
	n2->right = n5;
	n1->left = n2;
	n1->right = n3;
	
	is = Ancestor(n1, 52);
	if (is == -1)
		printf("\n 찾는 노드가 존재하지 않음");
}

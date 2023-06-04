#include <stdio.h>
#include <stdlib.h>
typedef struct TNode{
	int key;
	struct TNode *left, *right;
}TNode;

int Ancestor(TNode *root, int v){
	int a, b;
	if (!root) return -1;
	else if (root->key == v){
		printf("%d ", root->key);
		return root->key;
	}
	else{
		a = Ancestor(root->left, v);
		b = Ancestor(root->right, v);
		if (a != -1 || b != -1){
			printf("%d ", root->key);
			return root->key;
		}
		else
			return -1;
	}
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
	
	n1->key = 40;
	n2->key = 55;
	n3->key = 20;
	n4->key = 50;
	n5->key = 10;
	n6->key = 70;
	n7->key = 30;
	n8->key = 45;
	n9->key = 52;
	
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

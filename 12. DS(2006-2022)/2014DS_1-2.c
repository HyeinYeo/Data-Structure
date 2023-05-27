#include <stdio.h>
#include <stdlib.h>
typedef struct TNode{
	int key;
	struct TNode *left, *right;
}TNode;

int NearAncestor(TNode *root, int v, int w){
	if (!root) return -1;
	if ((v <= root->key && w >= root->key) || (v >= root->key && w <= root->key))
		return root->key;
	
	else if (v < root->key && w < root->key)
		return NearAncestor(root->left, v, w);
	
	else if (v > root->key && w > root->key)
		return NearAncestor(root->right, v, w);
}

int main(){
	int near;
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
	n2->key = 20;
	n3->key = 55;
	n4->key = 10;
	n5->key = 30;
	n6->key = 50;
	n7->key = 70;
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
	
	
	near = NearAncestor(n1, 70, 45);
	printf("%d", near);
	
}

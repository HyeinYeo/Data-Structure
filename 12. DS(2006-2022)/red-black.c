#include <stdio.h>

typedef struct Node{
	int data;
	int leftsize;
	struct Node *left, *right;
}Node;

int Rank(Node *root, Node *x){
	if (!x) return -1;
	if (root->data == x->data)
		return root->leftsize;
	else if (x->data < root->data)
		return Rank(root->left, x);
	else
		return root->leftsize + Rank(root->right, x);
}

int main(){
	int rank;
	Node n1 = {5, 1, NULL, NULL};
	Node n2 = {8, 1, NULL, NULL};
	Node n3 = {10, 1, NULL, NULL};
	Node n4 = {12, 1, NULL, NULL};
	Node n5 = {11, 2, &n3, &n4};
	Node n6 = {9, 2, &n2, &n5};
	Node n7 = {7, 2, &n1, &n6}; // 루트노드 
	
	rank = Rank(&n7, &n4);
	printf("%d", rank);
}

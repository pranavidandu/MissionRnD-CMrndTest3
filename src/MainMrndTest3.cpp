#include <stdio.h>
#include "FunctionHeadersMrndTest3.h"
#include <stdlib.h>"
struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct enode{
	char data[6];
	struct enode *left;
	struct enode *right;
};

struct node_dll{
	int data;
	struct node_dll *next;
	struct node_dll *prev;
};

void printArray(int *arr, int len){
	for (int i = 0; i < len; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void printDLL(struct node_dll *root){
	while (root != NULL){
		printf("%d ", root->data);
		root = root->next;
	}
	printf("\n");
}

void printBST(struct node * root){
	if (root != NULL){
		printBST(root->left);
		printf("%d ", root->data);
		printBST(root->right);
	}
}
struct node *newNode_spec(int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node * constructBinaryTree_spec(int *arr, int len){
	struct node *root = NULL;
	struct node *nodes[2005];
	for (int i = 0; i < len; i++){
		nodes[i] = newNode_spec(arr[i]);
	}
	int mid = (len / 2);
	for (int i = 0; i < mid; i++){
		struct node *curnode = nodes[i];
		struct node *leftnode = nodes[(i * 2) + 1];
		struct node *rightnode = nodes[(i * 2) + 2];
		if (curnode->data != -999){
			if (leftnode->data != -999){
				curnode->left = leftnode;
			}
			if (rightnode->data != -999){
				curnode->right = rightnode;
			}
		}
	}
	root = nodes[0];
	return root;
}
struct enode *newENode_spec(char *str)
{
	struct enode *temp = (struct enode *)malloc(sizeof(struct enode));
	int i = 0;
	while (str[i] != '\0'){
		temp->data[i] = str[i];
		i++;
	}
	temp->data[i] = '\0';
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

//If you copy this function ,make sure you remove _spec so It wont be two functions with same name
struct enode * constructEBinaryTree_spec(char strs[][6], int len){
	struct enode *root = NULL;
	struct enode *nodes[2005];
	for (int i = 0; i < len; i++){
		nodes[i] = newENode_spec(strs[i]);
	}
	int mid = (len / 2);
	for (int i = 0; i < mid; i++){
		struct enode *curnode = nodes[i];
		struct enode *leftnode = nodes[(i * 2) + 1];
		struct enode *rightnode = nodes[(i * 2) + 2];
		if (curnode->data[0] != 'X'){
			if (leftnode->data[0] != 'X'){
				curnode->left = leftnode;
			}
			if (rightnode->data[0] != 'X'){
				curnode->right = rightnode;
			}
		}
	}
	root = nodes[0];
	return root;
}
void inorder_recursive(struct enode *root){
	if (root->left != NULL){
		inorder_recursive(root->left);
	}
	printf("%s\t", root->data);
	if (root->right != NULL){
		inorder_recursive(root->right);
	}

	return;
}
int main(){
	//Test here
	char strs[][6] = { "+", "5", "*", "X", "X", "4", "3" };
	int len = 7;
	int ans = 17;
	struct enode *root = constructEBinaryTree_spec(strs, len);
	inorder_recursive(root);
	int actual = solve_tree(root);
	printf("actual %d\n", actual);
	/*int arr[] = { 1, 2, 3, 5, 0, -999, -999 };
	int len = 7;
	int actual_len = 5;
	int ans = 4;
	struct node *root = constructBinaryTree_spec(arr, len);
	int actual = get_missing_value(root, actual_len);
	printf("actual %d\n", actual);*/
};
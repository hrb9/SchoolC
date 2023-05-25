#include "BST.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "BST.h"
#include "TreePrintLibrary.h"

void insertNode(TreeNode* node, int data);
void freeTree(TreeNode* root);
void inorderPrint(TreeNode* root);
TreeNode* createNode(int data, TreeNode* left, TreeNode* right);


void initBST(BST* bst) {
	assert(bst != NULL);
	bst->root = NULL;

}
void insertBST(BST* bst, int value) {
		if (bst->root == NULL)
		bst->root = createNode(value, NULL, NULL);
	else
		insertNode(bst->root, value);//assumes bst->root is not null

}
void printTreeReversedInorder(BST* bst) {
	assert(bst != NULL);
	inorderPrint(bst->root);

}
void destroyBST(BST* bst) {
	assert(bst != NULL);
	freeTree(bst->root);

}

void inorderPrint(TreeNode* root)
{
	if (root == NULL) return;

	inorderPrint(root->left);
	printf("%d, ", root->element);
	inorderPrint(root->right);

}

void freeTree(TreeNode* root)
{
	if (root == NULL) return;

	freeTree(root->left);
	freeTree(root->right);
	free(root);
}

TreeNode* createNode(int data, TreeNode* left, TreeNode* right)
{
	TreeNode* Temp = (TreeNode*)calloc(1, sizeof(TreeNode));
	assert(Temp != NULL);
	Temp->element = data;
	Temp->left = left;
	Temp->right = right;
	return Temp;
}

void insertNode(TreeNode* root, int data)
{
	if (data <= root->element)
	{
		if (root->left == NULL)
			root->left = createNode(data, NULL, NULL);
		else
			insertNode(root->left, data);
	}
	else //right sub-tree
	{
		if (root->right == NULL)
			root->right = createNode(data, NULL, NULL);
		else
			insertNode(root->right, data);
	}
}

int sameHeightLeaves(BST* bst) {

}
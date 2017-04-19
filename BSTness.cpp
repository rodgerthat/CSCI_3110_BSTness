// BSTness.cpp : Defines the entry point for the console application.
//

#pragma once
#include <iostream>

using namespace std;

int BST[10];	// an array for the values... if we're storing the BST in an array. 

struct TreeNode {
	int item;
	TreeNode* lptr;
	TreeNode* rptr;
};

TreeNode* rootPtr = nullptr; // because initially the tree is empty

void BST_insert(TreeNode* &rootPtr, int x);
void BST_pre_order(TreeNode* rootptr);
void BST_in_order(TreeNode* rootptr);
void BST_post_order(TreeNode* rootPtr);


int main()
{

	// and awaaaaaayyyy we go!
	/*
	BST_insert(rootPtr, 1);
	BST_insert(rootPtr, 2);
	BST_insert(rootPtr, 3);
	BST_insert(rootPtr, 4);
	BST_insert(rootPtr, 5);
	BST_insert(rootPtr, 6);
	BST_insert(rootPtr, 7);
	BST_insert(rootPtr, 8);
	BST_insert(rootPtr, 9);
	BST_insert(rootPtr, 10);
	*/
	BST_insert(rootPtr, 2);
	BST_insert(rootPtr, 7);
	BST_insert(rootPtr, 4);
	BST_insert(rootPtr, 10);
	BST_insert(rootPtr, 5);
	BST_insert(rootPtr, 6);
	BST_insert(rootPtr, 3);
	BST_insert(rootPtr, 8);
	BST_insert(rootPtr, 9);
	BST_insert(rootPtr, 1);

	BST_in_order(rootPtr);
	cout << endl;
	BST_pre_order(rootPtr);
	cout << endl;
	BST_post_order(rootPtr);

    return 0;
}

void BST_insert(TreeNode* &rootPtr, int x) {

	// base case, the tree is empty
	if (rootPtr == nullptr) {
		// insert new root node
		rootPtr = new TreeNode;
		rootPtr->item = x;
		rootPtr->lptr = rootPtr->rptr = nullptr;
		return;
	}
	if (rootPtr->item < x) {
		BST_insert(rootPtr->rptr, x);
	}
	else {
		BST_insert(rootPtr->lptr, x);
	}
	return;
}

void BST_pre_order(TreeNode* rootPtr) {
	
	// base case, tree is empty
	if (rootPtr == nullptr) {
		return;
	}

	cout << rootPtr->item << " , ";

	if (rootPtr->lptr != NULL) {
		BST_pre_order(rootPtr->lptr);
	}
	if (rootPtr->rptr != NULL) {
		BST_pre_order(rootPtr->rptr);
	}
}

void BST_in_order(TreeNode* rootPtr) {
	if (rootPtr != NULL) {
		BST_in_order(rootPtr->lptr);
		cout << rootPtr->item << " , ";
		BST_in_order(rootPtr->rptr);;
	}
}

void BST_post_order(TreeNode* rootPtr) {


	if (rootPtr->lptr != NULL) {
		BST_post_order(rootPtr->lptr);
	}
	if (rootPtr->rptr != NULL) {
		BST_post_order(rootPtr->rptr);
	}

	cout << rootPtr->item << " , ";
}

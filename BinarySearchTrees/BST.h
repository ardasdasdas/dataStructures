#pragma once
#include<iostream>
struct  BSTNode {
	BSTNode *left;
	int key;
	BSTNode *right;
};
class BST {
	friend struct BSTNode;
public:
	int sameNmbr = 0;
	int counter = 0;
	BSTNode *root;
	int min();
	int max();
	int min(BSTNode* tree);
	int max(BSTNode* tree);
	BST();
	~BST();
	void insert(int key);
	BSTNode *Delete(BSTNode* agac, int silinecekdeger);
	BSTNode* find(int key);
	void printPostorder(BSTNode* node);
	void printInorder(BSTNode* node);
	void printPreorder(BSTNode* node);
	int leafCounter(BSTNode* node);
	void display(BSTNode *root, int indent);
	void sameNumber(BSTNode *root, int num, int& Same_num);
};
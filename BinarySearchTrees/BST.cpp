#include "BST.h"
#include<iostream>
#include<iomanip>
using namespace std;
/**
* @brief	: Constructor fonksiyonu.
*/
BST::BST()
{
	root = NULL;
}
/**
* @brief	: Destructor fonskiyonu.
*/
BST::~BST()
{
}
/**
* @brief	: Bu fonsiyon, aranan elemanin hangi dugumde oldugunu bulur.
* @param	: integer tipinde bir degisken alir.
*/
BSTNode* BST::find(int key) {
	BSTNode *p = root;
	while (p != NULL) {
		if (key == p->key)
			return p;
		else if (key < p->key)
			p = p->left;
		else
			p = p->right;
	}
	return NULL;
}
/**
* @brief	: Bu fonksiyon, agacta bulunan en kucuk sayiyi bulur ve return eder.
*/
int BST::min() {
	if (root == NULL) return NULL;
	BSTNode *p = root;
	while (p->left != NULL)
		p = p->left;
	return p->key;
}
/**
* @brief	: Bu fonksiyon, agacta bulunan en buyuk sayiyi bulur ve return eder.
*/
int BST::max() {
	if (root == NULL)
		return NULL;
	BSTNode *p = root;
	while (p->right != NULL)
		p = p->right;
	return p->key;
}
/**
* @brief	: Bu fonksiyon, agaca eleman ekleme islemini yapar.
* @param	: integer tipinde bir degisken alir.
*/
void BST::insert(int key) {
	BSTNode *pp = NULL;
	BSTNode *p = root;
	sameNumber(p, key, sameNmbr);
	counter++;
	while (p != NULL)
	{
		pp = p;
		if (key == p->key) return;
		else if (key < p->key)
			p = p->left;
		else
			p = p->right;
	}
	BSTNode *z = new BSTNode();
	z->key = key;
	z->left = z->right = NULL;
	if (root == NULL)
		root = z;
	else if (key < pp->key)
		pp->left = z;
	else
		pp->right = z;
}
/**
* @brief	: Bu fonksiyon, agactaki en kucuk elemani bulur.
* @param	: struct tipinde bir degisken alir.
*/
int BST::min(BSTNode* tree)
{
	BSTNode* temp = tree;

	while (temp->left != NULL)
		temp = temp->left;
	return temp->key;
}
/**
* @brief	: Bu fonksiyon, agactaki en buyuk elemani bulur.
* @param	: struct tipinde bir degisken alir.
*/
int BST::max(BSTNode* tree)
{
	BSTNode* temp = tree;
	while (temp->right != NULL)
		temp = temp->right;
	return temp->key;
}
/**
* @brief	: Bu fonksiyon, agactan eleman silme islemini yapar.
* @param	: struct tipinde bir degisken ve integer tipinde bir degisken alir.
*/
BSTNode *BST::Delete(BSTNode* tree, int number)
{
	if (tree == NULL)
	{
		return NULL;
	}
	if (number == tree->key)
	{
		if (tree->left == NULL && tree->right == NULL)
		{
			return NULL;
		}
		if (tree->right != NULL)
		{
			tree->key = min(tree->right);
			tree->right = Delete(tree->right, min(tree->right));
			return tree;
		}
		if (tree->left != NULL)
		{
			tree->key = max(tree->left);
			tree->left = Delete(tree->left, max(tree->left));
			return tree;
		}
	}
	if (number < tree->key)
	{
		tree->left = Delete(tree->left, number);
		return tree;
	}
	tree->right = Delete(tree->right, number);
	return tree;
}
/**
* @brief	: Bu fonksiyon, agacin elemanlarini postorder olarak sýralar.
* @param	: struct tipinde bir degisken alir.
*/
void BST::printPostorder(BSTNode* node)
{
	if (node == NULL)
		return;

	printPostorder(node->left);

	printPostorder(node->right);

	cout << node->key << " ";
}
/**
* @brief	: Bu fonksiyon, agacin elemanlarini inorder olarak sýralar.
* @param	: struct tipinde bir degisken alir.
*/
void BST::printInorder(BSTNode* node)
{
	if (node == NULL)
		return;

	printInorder(node->left);

	cout << node->key << " ";

	printInorder(node->right);
}
/**
* @brief	: Bu fonksiyon, agacin elemanlarini preorder olarak sýralar.
* @param	: struct tipinde bir degisken alir.
*/
void BST::printPreorder(BSTNode* node)
{
	if (node == NULL)
		return;

	cout << node->key << " ";

	printPreorder(node->left);

	printPreorder(node->right);
}
/**
* @brief	: Bu fonksiyon, agacin yaprak sayisini bulur.
* @param	: struct tipinde bir degisken alir.
*/
int BST::leafCounter(BSTNode* node) {
	if (node == NULL)
		return 0;
	if (node->left == NULL && node->right == NULL)
		return 1;
	else
		return leafCounter(node->left) + leafCounter(node->right);
}
/**
* @brief	: Bu fonksiyon, agacin ebeveyn ve cocuklar belli olacak sekilde siralar.
* @param	: struct ve integer tipinde bir degisken alir.
*/
void BST::display(BSTNode *root, int indent) //yan yazdýrýr
{
	if (root != nullptr)
	{
		display(root->right, indent + 4);
		if (indent > 0)
			cout << setw(indent) << " ";
		cout << root->key << endl;
		display(root->left, indent + 4);
	}
}
/**
* @brief	: Bu fonksiyon, agaca eklenen ayni sayilarin kac tane oldugunu hesaplar.
* @param	: struct tipinde birve integer tipinde iki degisken alir.
*/
void BST::sameNumber(BSTNode *root, int num, int& Same_num)
{
	if (root != NULL) {
		sameNumber(root->left, num, Same_num);
		if (num == root->key)
			Same_num++;
		sameNumber(root->right, num, Same_num);
	}
}

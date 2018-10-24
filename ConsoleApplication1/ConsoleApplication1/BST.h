#pragma once

#ifndef __BST_H__
#define __BST_H__

struct node
{
	int data;
	node* left;
	node* right;
};

class BST
{

private:

//	struct node
//	{
//		int data;
//		node* left;
//		node* right;
//	};

	node* root;

	node* makeEmpty(node* t);
    node* insert(int x, node* t);
    node* findMin(node* t);
    node* findMax(node* t);
    node* remove(int x, node* t);
    void inorder(node* t);
	//vector<int>& inorder(node* t);
    void preorder(node* t);
    void postorder(node* t);
    node* find(node* t, int x);

public:
	BST(void);
	~BST(void);
	void insert(int x);
	void remove(int x);
	void display();
	void displaypre();
	void displaypost();
	void search(int x);

};

#endif // __BST_H__
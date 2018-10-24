#include "BST.h"

#include <iostream>
using namespace std;

BST::BST(void)
{
    root = (node*) 0;
}

BST::~BST(void)
{
    root = makeEmpty(root);
}

node* 
BST::makeEmpty(node* t)
{
    if(t == (node*) 0)
        return (node*) 0;
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    return (node*) 0;
}

node* 
BST::insert(int x, node* t)
{
    if(t == (node*) 0)
    {
        t = new node;
        t->data = x;
        t->left = t->right = (node*) 0;
    }
    else if(x < t->data)
        t->left = insert(x, t->left);
    else if(x > t->data)
        t->right = insert(x, t->right);
    return t;
}

node* 
BST::findMin(node* t)
{
    if(t == (node*) 0)
        return (node*) 0;
    else if(t->left == (node*) 0)
        return t;
    else
        return findMin(t->left);
}

node* 
BST::findMax(node* t)
{
    if(t == (node*) 0)
        return (node*) 0;
    else if(t->right == (node*) 0)
        return t;
    else
        return findMax(t->right);

}

node* 
BST::remove(int x, node* t)
{
    node* temp;
    if(t == (node*) 0)
        return (node*) 0;
    else if(x < t->data)
        t->left = remove(x, t->left);
    else if(x > t->data)
        t->right = remove(x, t->right);
    else if(t->left && t->right)
    {
        temp = findMin(t->right);
        t->data = temp->data;
        t->right = remove(t->data, t->right);
    }
    else
    {
        temp = t;
        if(t->left == (node*) 0)
            t = t->right;
        else if(t->right == (node*) 0)
            t = t->left;
        delete temp;
    }

    return t;
}

void 
BST::inorder(node* t)
{
    if(t == (node*) 0)
        return;
    inorder(t->left);
    cout << t->data << " ";
    inorder(t->right);
}

void 
BST::preorder(node* t)
{
    if(t == (node*) 0)
        return;
    cout << t->data << " ";
    preorder(t->left);
    preorder(t->right);
}

void 
BST::postorder(node* t)
{
    if(t == (node*) 0)
        return;
    postorder(t->left);
    postorder(t->right);
    cout << t->data << " ";
}

node* 
BST::find(node* t, int x)
{
    if(t == (node*) 0)
        return (node*) 0;
    else if(x < t->data)
        return find(t->left, x);
    else if(x > t->data)
        return find(t->right, x);
    else
        return t;
}

void 
BST::insert(int x)
{
    root = insert(x, root);
}

void 
BST::remove(int x)
{
    root = remove(x, root);
}

void 
BST::display()
{
    inorder(root);
    cout << endl;
}

void 
BST::displaypre()
{
    preorder(root);
    cout << endl;
}

void 
BST::displaypost()
{
    postorder(root);
    cout << endl;
}

void 
BST::search(int x)
{
    root = find(root, x);

}

// This file contains the definition of our self-defined myAvl class, wherein an AVL Tree is implemented via nodes and pointers.
#include<bits/stdc++.h>
using namespace std;
struct node
{
	node* left;
	node* right;
	int data;
	int height;
	node(int value)	
	{
		data=value;
		left=NULL;
		right=NULL;
		height=1;
	}
};
class myAvl( )
{
private: node* root;
		int count;
public:
	myAvl()
	{
		root=NULL;
		count=0;
	}
	int height(node* a)
	{
		if(a==NULL)
			return 0;
		return a->height;
	}
	node* rightRotate(node* y)
	{
		node* x=y->left;
		node* t2=x->right;


		x->right=y;
		y->left=t2;

		x->height=max(height(x->left),height(x->right))+1;
		y->height=max(height(y->left),height(y->right))+1;
		return x;
	}
	node* leftRotate(node * x)
	{
		node* y=x->right;
		node* t2=y->left;

		y->left=x;
		x->right=t2;

		x->height=max(height(x->left),height(x->right))+1;
		y->height=max(height(y->left),height(y->right))+1;
		return y;
	}
	int getBalance(node* a)
	{
		if(a==NULL)
			return 0;
		return (height(a->left)-height(a->right));
	}
	node* insert(node* a,int value)
	{
		if(root==NULL)
		{
			root->data=value;
			count++;
			return root;
		}
		if(value<root->data)
		{
			root->left=insert(root->left,value);
		}
		else 
		{
			root->right=insert(root->right,value);
		}
		int balance=getBalance(root);

		if(balance > 1 && value < root->left->data)
		{
			return rightRotate(root);
		}
		 if(balance < -1 && value > root->right->data)
		{
			return leftRotate(root);
		}
		 if (balance > 1 && value > root->left->data)
	    {
	        root->left =  leftRotate(root->left);
	        return rightRotate(root);
	    }
	    if (balance < -1 && value > root->left->data)
	    {
	        root->left =  leftRotate(root->left);
	        return rightRotate(root);
	    }
	    count++;
	    return root;
	}
	node* search(node* root,int value)
	{
		if(root==NULL)
			return NULL;
		node* curnode=root;
		while(1)
		{
			if(curnode->data==value)
				return root;
			else if(curnode->data<value)
			{
				if(curnode->right!=NULL)
					curnode=curnode->right;
				else
					break;
			}
			else if(curnode->data > value)
			{
				if(curnode->left!=NULL)
					curnode=curnode->left;
				else
					break;
			}
			else 
			{
				return curnode;
			}
		}
		return NULL;
	}
	int minm(node* root)
	{
		node* cur=root;
		while(cur->left!=NULL)
		{
			cur=cur->left;
		}
		return cur->data;
	}
	node* deletef(node* root,int value)
	{
		if(root==NULL)
			return NULL;
		if(root->data < value)
		{
			root->right=deletef(root->right,value);
		}
		else if(root->data > value)
		{
			root->left=deletef(root->left,value);
		}
		else
		{
			if(root->left==NULL && root->right!=NULL)
				return root->right;
			if(root->left==NULL && root->right==NULL)
				return NULL;
			if(root->left!=NULL and root->right==NULL)
				return root->left;
			else
			{
				root->data=minm(root->right);
				root->right=deletef(root->right,value);
			}
		}
		return root;
	}
	int size(node* root)
	{
		return count;
	}
	int top(node* root)
	{
		return root->data;
	}
}


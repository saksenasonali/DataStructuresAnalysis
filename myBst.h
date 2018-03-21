// This file contains the definition of our self-defined myBst class, wherein a Binary Search Tree is implemented via nodes and pointers.
#include<bits/stdc++.h>
struct node
{
	int data;
	node* left;
	node* right;
	node(int val)
	{
		data=val;
		left=NULL;
		right=NULL;
	}
};
class myBst
{
private:

	node* root;
	int count;

	int minHelper(node* root)
	{
		while(root->left!=NULL)
		{
			root=root->left;
		}
		return root->data;
	}

	node* deleteHelper(node* root,int x)
	{
		if(root->data==x)
		{
			if(root->left==NULL && root->right!=NULL)
				return root->right;
			else if(root->left!=NULL && root->right==NULL)
				return root->left;
			else if (root->left!=NULL && root->right!=NULL)
			{
				int minm=minHelper(root->right);
				root->data=minm;
				root->right=deleteHelper(root->right,minm);
			}
			else
				root=NULL;
		}
		else
		{
			if(root->data<x)
			{
				root->right=deleteHelper(root->right,x);
			}
			else
			{
				root->left=deleteHelper(root->left,x);
			}
		}
		return root;
	}

public:
	myBst()
	{
		root=NULL;
		count=0;
	}

	int size()
	{
		return count;
	}
	void insert(int x)
	{
		node* temp=new node(x);
		count++;
		if(count==1)
		{
			root=temp;
			return;
		}
		node* curnode=root;
		while(1)
		{
			if(curnode->data>x)
			{
				if(curnode->left!=NULL)
					curnode=curnode->left;
				else
				{
					curnode->left=temp;
					break;
				}
			}
			else
			{
				if(curnode->right!=NULL)
					curnode=curnode->right;
				else
				{
					curnode->right=temp;
					break;
				}
			}
		}
		
	}


	int top()
	{
		return root->data;
	}

	void deletex(int x)
	{
		root = deleteHelper(root,x);

	}


};

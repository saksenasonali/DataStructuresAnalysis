// This file contains the definition of our self-defined myBst class, wherein a Binary Search Tree is implemented via nodeBsts and pointers.

struct nodeBst
{
	int data;
	nodeBst* left;
	nodeBst* right;
	nodeBst(int val)
	{
		data=val;
		left=NULL;
		right=NULL;
	}
};

class myBst
{
private:

	nodeBst* root;
	int count;

	int minHelper(nodeBst* root)
	{
		while(root->left!=NULL)
		{
			root=root->left;
		}
		return root->data;
	}

	nodeBst* deleteHelper(nodeBst* root,int x)
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
		nodeBst* temp=new nodeBst(x);
		count++;
		if(count==1)
		{
			root=temp;
			return;
		}
		nodeBst* curnodeBst=root;
		while(1)
		{
			if(curnodeBst->data>x)
			{
				if(curnodeBst->left!=NULL)
					curnodeBst=curnodeBst->left;
				else
				{
					curnodeBst->left=temp;
					break;
				}
			}
			else
			{
				if(curnodeBst->right!=NULL)
					curnodeBst=curnodeBst->right;
				else
				{
					curnodeBst->right=temp;
					break;
				}
			}
		}
		
	}
	
	int search(int value)
	{
		if(root==NULL)
			return -1;
		nodeBst* curnodeBst=root;
		while(1)
		{
			if(curnodeBst->data==value)
				return 1;
			else if(curnodeBst->data<value)
			{
				if(curnodeBst->right!=NULL)
					curnodeBst=curnodeBst->right;
				else
					break;
			}
			else if(curnodeBst->data > value)
			{
				if(curnodeBst->left!=NULL)
					curnodeBst=curnodeBst->left;
				else
					break;
			}
			else 
			{
				return 1;
			}
		}
		return -1;
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

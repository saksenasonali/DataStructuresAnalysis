// This file contains the definition of our self-defined myAvl class, wherein an AVL Tree is implemented via nodes and pointers.

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

class myAvl
{
private: 
	node* root;
	int count;
	
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

		y->height=max(height(y->left),height(y->right))+1;
		x->height=max(height(x->left),height(x->right))+1;

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
				root = root->right;
			if(root->left==NULL && root->right==NULL)
				return NULL;
			if(root->left!=NULL and root->right==NULL)
				root = root->left;
			else
			{
				root->data=minm(root->right);
				root->right=deletef(root->right,value);
			}
		}

		int balance = getBalance(root);
 
		// If this node becomes unbalanced, then there are 4 cases

		// Left Left Case
		if (balance > 1 && getBalance(root->left) >= 0)
		    return rightRotate(root);

		// Left Right Case
		if (balance > 1 && getBalance(root->left) < 0)
		{
		    root->left =  leftRotate(root->left);
		    return rightRotate(root);
		}

		// Right Right Case
		if (balance < -1 && getBalance(root->right) <= 0)
		    return leftRotate(root);

		// Right Left Case
		if (balance < -1 && getBalance(root->right) > 0)
		{
		    root->right = rightRotate(root->right);
		    return leftRotate(root);
		}

		return root;
	}

	node* insertHelper(node* root,int value)
	{
		if(root==NULL)
		{
			root = new node(value);
			count++;
			return root;
		}
		if(value<root->data)
		{
			root->left=insertHelper(root->left,value);
		}
		else 
		{
			root->right=insertHelper(root->right,value);
		}
		int balance=getBalance(root);

		count++;

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
		if (balance < -1 && value < root->right->data)
		{
			root->right =  rightRotate(root->right);
			return leftRotate(root);
		}
		return root;
	}

public:
	myAvl()
	{
		root=NULL;
		count=0;
	}

	void insert(int val)
	{
		root = insertHelper(root, val);
	}

	int search(int value)
	{
		if(root==NULL)
			return -1;
		node* curnode=root;
		while(1)
		{
			if(curnode->data==value)
				return 1;
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
				return 1;
			}
		}
		return -1;
	}
	
	void deletex(int val)
	{
		root = deletef(root, val);
	}
	
	int size()
	{
		return count;
	}
	int top()
	{
		return root->data;
	}
};


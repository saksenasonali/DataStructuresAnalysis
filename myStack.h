// This file contains the definition of our self-defined myStack class, wherein a stack is implemented via Array.
class myStack
{
private:
	int top1;
	int a[100005];

public:
	myStack()
	{
		top1 = -1;
	}

	int size()
	{
		return top1+1;
	}

	int empty()
	{
		return (top1+1==0);
	}

	void push(int x)
	{
		top1++;
		a[top1]=x;
	}

	void pop()
	{
		top1--;
	}

	int top()
	{
		return a[top1];
	}
};

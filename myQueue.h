// This file contains the definition of our self-defined myQueue class, wherein a queue is implemented via Array.

class myQueue
{
private:
	int front;
	int rear;
	int n;
	int a[100005];

public:
	myQueue()
	{
		front = -1;
		rear=-1;
		n=100005;
	}

	int size()
	{
		if(rear==-1)
			return 0;
		else if(rear>=front)
			return (rear-front+1);
		else
		{
			return (n+1+rear-front);
		}
	}


	void push(int x)
	{
		if(rear==-1)
			front++;

		if(rear==n-1)
			rear=0;
		else
			rear++;

		a[rear]=x;
	}

	void pop()
	{
		if(rear==front)
		{
			rear=-1;
			front=-1;
		}

		if(front==n-1)
			front=0;
		else
			front++;
	}

	int top()
	{
		return a[front];
	}
};

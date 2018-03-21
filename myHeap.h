// This file contains the definition of our self-defined myHeap class, wherein a Min-Heap is implemented via Array.
class myHeap
{
private:

	int a[100005];
	int n;

public:
	myHeap()
	{
		n=0;
	}

	int size()
	{
		return n;
	}
	void insert(int x)
	{
		n++;
		a[n]=x;
		int j=n;
		int temp=0;
		while(j>1)
		{
			if(a[j]<a[j/2])
			{
				temp=a[j/2];
				a[j/2]=a[j];
				a[j]=temp;
			}
			else
				break;
			j=j/2;
		}		
	}


	int top()
	{
		return a[1];
	}

	void remove_min()
	{
		int minm=a[1];
		a[1]=a[n];
		n--;
		int l=n;
		int temp=0;
		while(l<=(n)/2)
			{
				if(2*l==n)
				{
					if(a[l]>a[2*l])
					{
						temp=a[2*l];
						a[2*l]=a[l];
						a[l]=temp;
					}
					break;
				}
				if(a[l]<a[2*l+1] && a[l]>a[2*l])
				{
					temp=a[l];
					a[l]=a[2*l];
					a[2*l]=temp;
					l=2*l;
				}
				else if(a[l]>a[2*l+1] && a[l]<a[2*l])
				{
					temp=a[l];
					a[l]=a[2*l+1];
					a[2*l+1]=temp;
					l=2*l+1;
				}
				else if(a[l]<a[l*2] && a[l] < a[2*l+1])
					break;
				else
				{
					if(a[2*l]<a[2*l+1])
					{
						temp=a[2*l];
						a[2*l]=a[l];
						a[l]=temp;
						l=2*l;
					}
					else
					{
						temp=a[l];
						a[l]=a[2*l+1];
						a[2*l+1]=temp;
						l=2*l+1;
					}
				}

			}

	}

};

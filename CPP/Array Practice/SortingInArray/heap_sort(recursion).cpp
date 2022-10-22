#include<iostream>
using namespace std;
void swap(int a[],int larger,int j)
{
	int temp;
	temp=a[larger];
	a[larger]=a[j];
	a[j]=temp;
}
void display(int a[],int n)
{
	for(int i=1;i<=n;i++)
	cout<<a[i]<<" ";
}
void heapify(int a[],int i,int j)
{
	int l,r,larger;
	if(2*j>i)   //if no child is present.
		return;
	l=a[2*j];
	if((2*j+1)<=i)      //if right child is present.
	{
		r=a[2*j+1];
		larger=((l>=r)?(2*j):(2*j+1));   //finding which is larger out of left and right child.
	}
	else
		larger=2*j;
	if(a[larger]>a[j])               //comparing between larger between left and right by its parent,i.e,root.
	{
		swap(a,larger,j);
		heapify(a,i,larger);    //as if swapping takes place then the new subtree may not satisfy max heap property.
	}
}
void build_max_heap(int a[],int n)  //building max heap from a array-->checking all nodes as a root leaving leaf nodes
{
	for(int j=n/2;j>0;j--)
		heapify(a,n,j);
}
void heapsort(int a[],int n)
{
	build_max_heap(a,n);                                               //   O(logn)
	// one by one keeping the largest element in an array at the end.
	swap(a,1,n);               
	for(int i=n-1;i>0;i--)                                            //    O(nlogn)
	{ 
		heapify(a,i,1);      //comparing from root element as below it is arleady a max heap but root element after swap may not satisfy max heap property.
		swap(a,1,i);
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n+1];
	a[0]=0;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	heapsort(a,n);
	display(a,n);
}

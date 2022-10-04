#include <iostream>
using namespace std;
int main()
{
	char sym;
	int rows;
	cout<<"Enter symbol :";
	cin>>sym;
	cout<<"Enter number of rows :";
	cin>>rows;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<=i;j++)
		{
			cout<<sym;
		}
		cout<<"\n";
	}

	return 0;

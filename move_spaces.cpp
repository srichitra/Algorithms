#include <iostream>
#include<string.h>
using namespace std;
void mySwap(char A[],int i,int j)
{
	char temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}
void moveChars(char A[])
{
	int i, j;
	i=strlen(A) - 1;
	j=i;
	for(;j>=0;j--)
	{
		if(A[j]!=' ')
		{
		
			mySwap(A,i--,j);
		}
	}
	
}
int main()
{
	char args[] = "move these";
	cout<<"Value of A before moving, "<<args;
	moveChars(args);
	cout<<"\nValue of A before moving, "<<args;
	return 0;
}
#include <iostream>
#include<cmath>
using namespace std;
struct LinkedList
{
	int data;
    LinkedList *next;
    LinkedList(int d)
    {
    	data = d;
    	next = NULL;
    }
};
class ListNum
{
	public:

    LinkedList* addList(LinkedList *a,LinkedList *b)
    {
    	LinkedList *atemp;
    	LinkedList *btemp,*ans;
    	int acount = 0;
    	int bcount = 0;
    	int aVal,bVal;
    	atemp = a;
    	btemp = b;
    	for(;atemp->next!=NULL;atemp=atemp->next)
    	{
    		acount++;
    	}
    	for(;btemp->next!=NULL;btemp=btemp->next)
    	{
    		bcount++;
    	}
    	atemp = a;
    	btemp = b;
    	for(int count=acount;count>=0;count--)
    	{
    		aVal +=pow(atemp->data,count);
    	}
    	for(int count=bcount;count>=0;count--)
    	{
    		bVal +=pow(btemp->data,count);
    	}
    		int sum = aVal + bVal;
         ans = createLinkedList(sum);   
    	}
    	
    LinkedList* createLinkedList(int data)
    {
    	int d=0;
    	LinkedList *finalans= new LinkedList(d);
    	while(data!=0)
    	{
    		d = data%10;	
    		data = data/10;
    		finalans->data = d;
    		finalans->next = new LinkedList(d);
    		
    	}
    	return finalans;
    	
    }
	
    
};
int main() {
	// your code goes here
	ListNum m = new ListNum();
	LinkedList *aL = m.createLinkedList(9);
	LinkedList *aR = m.createLinkedList(0);
	aL->next = aR;
	aR->next = NULL;
	LinkedList *bL = m.createLinkedList(8);
	bL->next = NULL;
	LinkedList *answer = m.addList(aL,bL);
	LinkedList *temp = answer;
	cout<<"The answer is";
	for(;temp->next != NULL;temp=temp->next)
	{
		cout<<temp->data;
	}
	return 0;
}
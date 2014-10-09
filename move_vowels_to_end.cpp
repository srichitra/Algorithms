// move_vowels_to_end.cpp : Defines the entry point for the console application.
/*Given a linked list containing character in each node,
segregate its nodes in such a way that all nodes containing a vowel are moved to the end of the linked list. 
We will have to maintain the order.
*/
 
#include <iostream>
#include <string.h>
using namespace std;
struct Node
{
    char data;
        Node *pNext;
        Node(char ch)
        {
                data = ch;
                pNext = NULL;
        }
};
Node* moveVowelsToEnd(Node* list)
{
        if(list == NULL)
                return NULL;
 
        Node *lastNode = NULL, *prevNode = NULL , *headNode = NULL;
        int count = 0;
        for(lastNode = list;lastNode->pNext != NULL; lastNode=lastNode->pNext){
                count++;
        };
 
        for(Node *temp = list;temp!= NULL;)
        {
                if(count<0)
                        break;
                count--;
                //Check for vowel
                bool bIsVowel = false;
                switch(temp->data)
                {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                        bIsVowel = true;
                        break;
                default:
                        bIsVowel = false;
                        break;
                }
                if(bIsVowel)
                {
                        if(prevNode == NULL)
                        {
                                lastNode->pNext = temp;
                                temp = temp->pNext;
                                lastNode = lastNode->pNext;
                                lastNode->pNext = NULL;                         
                        }
                        else{
                                prevNode->pNext = temp->pNext;
                                lastNode->pNext = temp;
                                lastNode = lastNode->pNext;
                                lastNode->pNext = NULL;
                                temp = prevNode->pNext;
                        }
                }
                else{
                        if(headNode == NULL)
                                headNode = temp;
                        prevNode = temp;
                        temp=temp->pNext;
                }               
        }
        if(headNode == NULL)
                headNode = list;
 
        return headNode;
}
//Method to cleanup the linked list
void CleanupList(Node *list)
{
        while(list != NULL)
        {
                Node *tmpNode = list;
                list = list->pNext;
                delete tmpNode;
        }
}
int main(int argc, char* argv[])
{
        char string[100];
        Node *list = NULL, *prevNode = NULL;
        cout<<"Enter string"<<endl;
        cin>>string;
        for(int i=0;i<strlen(string);i++)
        {
                Node *node = new Node(string[i]);
                if(list == NULL){
                        list = node;
                        prevNode = node;
                }
                else
                {
                        prevNode->pNext = node;
                        prevNode = node;
                }
        }
 
        list = moveVowelsToEnd(list);
        cout<<"String after moving vowels to end:"<<endl;
        for(Node *tmpNode=list;tmpNode!= NULL; tmpNode=tmpNode->pNext)
                cout<<tmpNode->data;
 
        CleanupList(list);
        return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef struct ListNode{
    int val;
    ListNode *next,*prev;
    ListNode(int v){
        val=v;
        next=prev=NULL;
    }
}ListNode;

class Stack {
    public:
    ListNode *head,*tail,*middle;
    int co;
    Stack(){
        head=tail=middle=NULL;
        co=0;
    }
    void push(int v){
        if(head==NULL){
            head=new ListNode(v);
            tail=head;
        }
        else{
            ListNode* t=new ListNode(v);
            t->next=head;
            head->prev=t;
            head=t;
        }
        ++co;
        if(co==1){
            middle=head;
        }
        else{
            if(!(co&1)){
                middle=middle->prev;
            }
        }
    }

    void pop(){
        if(co==0){
            cout<<"stack is empty\n";
            return;
        }
        ListNode* t=head;
        head=head->next;
        free(t);
        --co;
        if(co==0){
            head=tail=middle=NULL;
            return;
        }
        if(co==1){
            middle=head;
        }
        else{
            if(co&1){
                middle=middle->next;
            }
        }
    }
    int getmiddle(){
        if(co==0){
            cout<<"stack is empty\n";
            return -1;
        }
        else{
            return middle->val;
        }
    }
    void popmiddle(){
        if(co==0){
            cout<<"stack is empty\n";
            return;
        }
        --co;
        ListNode* t=middle;
        if(co==0){
            free(t);
            head=tail=middle=NULL;
            return;
        }
        if((co&1)){
            middle=middle->next;
            if(t->prev==NULL){
                head=middle;
                if(middle)middle->prev=NULL;
                free(t);
            }
            else{
                t->prev->next=middle;
                if(middle)middle->prev=t->prev;
                free(t);
            }
        }
        else{
            middle=middle->prev;
            middle->next=t->next;
            if(t->next!=NULL){
                t->next->prev=middle;
            }
            free(t);
        }
    }
    void print(){
        if(head==NULL){
            cout<<"stack is empty\n";
            return;
        }
        for(ListNode* t=head;t!=NULL;t=t->next){
            cout<<t->val<<" ";
        }
        cout<<"\n";
    }
};
        
int main(){
    Stack s;
    while(1){
        int op;
        cin>>op;
        switch(op){
            case 0:
            int x;
            cin>>x;
            s.push(x);
            break;
            case 1:
            s.pop();
            break;
            case 2:
            s.print();
            break;
            case 3:
            cout<<s.getmiddle()<<"\n";
            break;
            case 4:
            s.popmiddle();
            break;
        }
    }
    return 0;
}
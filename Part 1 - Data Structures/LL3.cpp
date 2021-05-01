#include<iostream>
#include<inttypes.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* newnode(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    return temp;
}

/*Linked Lists: Two-Pointer Methods and LLtoDLL Conversion
findMiddle,nthNodeEnd,nNodesEndSum,detectLoop,loopLength,rearrangeAlt,findPair*/

Node* findMiddle(Node* head){
    if(head==NULL) return NULL;
    Node* fast=head;
    Node* slow=head;
    while(fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

Node* nthNodeEnd(Node* head,int n){
    Node* first=head;
    Node* second=head;
    for(int i=0;i<n;i++)
        first=first->next;
    while(first){
        first=first->next;
        second=second->next;
    }
    return second;
}

int nNodesEndSum(Node* head,int n){
    Node* first=head;
    Node* second=head;

    int sum=0,total=0;
    for(int i=0;i<n;i++){
        total+=first->data;
        first=first->next;
    }
    while(first){
        total+=first->data;
        sum+=second->data;
        first=first->next;
        second=second->next;
    }
    return total-sum;
}

bool detectLoop(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}

int loopLength(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            Node* cur = slow; int c=1;
            while(cur->next!=slow){
                cur=cur->next;
                c++;
            }
            return c;
        }
    }
    return 0;
}

Node* rearrangeAlt(Node* head){
    if(head==NULL) return NULL;
    Node* odd=head;
    Node* even=head->next;

    Node* evenHead=head->next;

    while(1){
        if(odd==NULL || even==NULL || even->next==NULL){
            odd->next=evenHead; break;
        }

        if(odd->next==NULL){
            even->next=NULL;
            odd->next=evenHead; break;
        }

        odd->next=odd->next->next;
        odd=odd->next;

        even->next=even->next->next;
        even=even->next;
    }
    return head;
}

Node* XOR(Node* node1,Node* node2){
    Node* temp = (Node*) ((uintptr_t)node1 ^ (uintptr_t)node2);
    return temp;
}

void convertToDLL(Node* head){
    Node* prev=NULL;
    Node* next=NULL;

    while(head){
        next=head->next;
        head->next = XOR(next,prev);
        prev=head;
        head=next;
    }
}

void goNext(Node** curPtr, Node** prevPtr){
    Node* temp = *curPtr;
    *curPtr = XOR((*curPtr)->next,*prevPtr);
    *prevPtr=temp;
}

void goPrev(Node** curPtr, Node** nextPtr){
    Node* temp = *curPtr;
    *curPtr = XOR((*curPtr)->next,*nextPtr);
    *nextPtr=temp;
}

/*
bool findPair(Node* head, int sum){
    //Constraint: List should be a sorted doubly linked list
    Node *first=head, *second=head;
    while(second->next) second=second->next;
    bool flag=false;
    while(first && second && first!=second && first!=second->next){
        if(first->data+second->data<sum)
            first=first->next;
        else if(first->data+second->data>sum)
            second=second->prev;
        else{
            flag = true;
            cout<<first->data<<" "<<second->data<<endl;
            first=first->next;
            second=second->prev;
        }
    }
    return flag;
}
*/

bool findPair(Node* head, int sum){
    //Constraint: List should be sorted.
    Node *first=head,*second=head;
    Node *next=NULL, *prev=NULL;
    while (second->next!=prev) goNext(&second,&prev);
    prev=NULL;

    bool flag=false;
    while (first && second && first!=second && first!=next){
        if (first->data + second->data < sum)
            goNext(&first,&prev);
        else if(first->data + second->data > sum)
            goPrev(&second,&next);
        else{
            flag = true;
            goNext(&first,&prev);
            goPrev(&second,&next);
        }
    }
    return flag;
}

int main(){
    Node* head = newnode(1);
    head->next = newnode(3);
    head->next->next = newnode(5);
    head->next->next->next = newnode(7);
    head->next->next->next->next = newnode(9);
    head->next->next->next->next->next = newnode(11);

    cout<<nthNodeEnd(head,1)->data<<endl<<endl;

    Node* cur=head;
    while(cur){
        cout<<cur->data<<endl;
        cur=cur->next;
    }
    return 0;
}

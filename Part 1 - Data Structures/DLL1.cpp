#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node* newnode(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

/*Doubly Linked Lists: Basic Functions
push,append,ins,del,reverse_list*/

Node* push(Node* head,int data){
    Node* temp = newnode(data);
    temp->next = head;
    if(head) head->prev = temp;
    return temp;
}

Node* append(Node* head, int data){
    Node* temp = newnode(data);
    if(head==NULL) return temp;
    Node* cur=head;
    while(cur->next)
        cur=cur->next;
    cur->next=temp;
    temp->prev=cur;
    return head;
}

Node* ins(Node* head, int data,int n){
    Node* temp = newnode(data);
    if(head==NULL) return temp;
    if(n==0){
        temp->next=head;
        head->prev=temp;
        return temp;
    }
    Node* cur=head;
    for(int i=0;i<n-1;i++)
        cur=cur->next;
    temp->next=cur->next;
    cur->next=temp;
    temp->prev=cur;
    if(cur->next) cur->next->prev=temp;
    return head;
}

Node* del(Node* head,int n){
    Node* cur=head;
    if(n==0) return head->next;
    for(int i=0;i<n-1;i++)
        cur=cur->next;
    if(cur->next) cur->next = cur->next->next;
    if(cur->next) cur->next->prev = cur;
    return head;
}

Node* reverse_list(Node* head){
    Node* cur1 = NULL;
    Node* cur2 = head;

    while(cur2){
        cur1 = cur2->prev;
        cur2->prev = cur2->next;
        cur2->next = cur1;
        cur2 = cur2->prev;
    }
    return cur1->prev;
}

int main(){
    Node* head = NULL;
    head = push(head,7);
    head = push(head,5);
    head = push(head,3);
    head = push(head,1);

    Node* cur=head;
    while(cur){
        cout<<cur->data<<endl;
        cur=cur->next;
    }
    return 0;
}

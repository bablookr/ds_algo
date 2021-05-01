#include <iostream>
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

/*Linked List: Basic functions
push,append,ins,del,reverse_list*/

Node* push(Node* head,int data){
    Node* temp = newnode(data);
    temp->next = head;
    return temp;
}

Node* append(Node* head, int data){
    Node* temp = newnode(data);
    if(head==NULL) return temp;
    Node* cur=head;
    while(cur->next){
        cur=cur->next;
    }
    cur->next=temp;
    return head;
}

Node* ins(Node* head,int data,int n){
    Node* temp = newnode(data);
    if(n==0){
        temp->next=head;
        return temp;
    }
    Node* cur=head;
    for(int i=0;i<n-1;i++)
        cur=cur->next;
    temp->next=cur->next;
    cur->next=temp;
    return head;
}

Node* del(Node* head,int n){
    Node* cur=head;
    if(n==0) return head->next;
    for(int i=0;i<n-1;i++)
        cur=cur->next;
    cur->next=cur->next->next;
    return head;
}

Node* reverse_list(Node* head){
    Node* cur1 = NULL;
    Node* cur2 = head;

    while(cur2){
        Node* cur3 = cur2->next;
        cur2->next = cur1;
        cur1 = cur2;
        cur2 = cur3;
    }
    return cur1;
}

int main(){
    Node* head = newnode(1);
    head->next = newnode(3);
    head->next->next = newnode(5);
    head->next->next->next = newnode(7);

    head  = reverse_list(head);

    Node* cur=head;
    while(cur){
        cout<<cur->data<<endl;
        cur=cur->next;
    }
    return 0;
}

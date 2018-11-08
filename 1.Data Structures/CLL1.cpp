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

/*Circular Linked Lists: Basic Functions
push/append,ins,del,reverse_CLL,print_CLL*/

Node* push(Node* head,int data){
    Node* temp=newnode(data);
    if(head==NULL){
        temp->next=temp;
        return temp;
    }
    Node* cur=head;
    while(cur->next!=head){
        cur=cur->next;
    }
    cur->next=temp;
    temp->next=head;
    return temp;
}

Node* ins(Node* head, int data, int n){
    if(n==0) return push(head,data);
    Node* temp = newnode(data);
    Node* cur=head;
    for(int i=0;i<n-1;i++)
        cur=cur->next;
    temp->next=cur->next;
    cur->next=temp;
    //cur=push(cur->next,data);
    return head;
}

Node* del(Node* head,int n){
    Node* cur=head;
    if(n==0){
        cur=cur->next;
        while(cur->next!=head){
            cur=cur->next;
        }
        cur->next=head->next;
        return cur->next;
    }
    for(int i=0;i<n-1;i++)
        cur=cur->next;
    cur->next=cur->next->next;
    return head;
}

Node* reverse_CLL(Node* head){
    Node* cur1 = head;
    Node* cur2 = head->next;
    Node* cur3 = NULL;

    while(cur2!=head){
        cur3 = cur2->next;
        cur2->next = cur1;
        cur1 = cur2;
        cur2 = cur3;
    }
    head->next = cur1;
    return cur1;
}

void printCLL(Node* head){
    cout<<head->data<<endl;
    Node* cur=head->next;
    while(cur!=head){
        cout<<cur->data<<endl;
        cur=cur->next;
    }
}

int main(){
    Node* head=NULL;
    head=push(head,7);
    head=push(head,5);
    head=push(head,3);
    head=push(head,1);

    printCLL(head);
    return 0;
}

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

Node* push(Node* head,int data){
    Node* temp = newnode(data);
    temp->next = head;
    if(head) head->prev = temp;
    return temp;
}

/*Doubly Linked List: Algorithms
linear_search,bubble_sort,insertion_sort,selection_sort,merge_sort,quick_sort
merge_lists(Sorted Union), intersect_lists(Sorted Intersection)*/

Node* bubbleSwap(Node* head,Node* tail){
    for(Node* cur = head;cur!=tail;cur=cur->next){
        if(cur->data>cur->next->data)
            swap(cur->data,cur->next->data);
    }
    return head;
}

Node* findMin(Node* head,Node* tail){
    Node* minNode = head;
    for(Node* cur=head;cur!=tail->next;cur=cur->next){
        if(cur->data<minNode->data) minNode = cur;
    }
    return minNode;
}

Node* sortedInsert(Node* head,int key){
    //Constraint: List should be sorted
    Node* temp = newnode(key);
    if(head==NULL) return temp;
    if(head->data>temp->data){
        temp->next=head;
        head->prev=temp;
        return temp;
    }
    Node* cur;
    for(cur=head;cur->next!=NULL;cur=cur->next){
        if(cur->next->data>temp->data) break;
    }
    temp->next=cur->next;
    if(cur->next) temp->next->prev=temp;
    cur->next=temp;
    temp->prev=cur;
    return head;
}

Node* merge_lists(Node* head1, Node* head2){
    //Constraint: Lists should be sorted
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;

    if(head1->data<=head2->data){
        head1->next = merge_lists(head1->next,head2);
        head1->next->prev=head1;
        head1->prev=NULL;
        return head1;
    }
    else{
        head2->next = merge_lists(head1,head2->next);
        head2->next->prev=head2;
        head2->prev=NULL;
        return head2;
    }
}

Node* intersect_lists(Node* head1,Node* head2){
    //Constraints: Lists should be sorted
    if(head1==NULL || head2==NULL)
        return NULL;
    if(head1->data<head2->data)
        return intersect_lists(head1->next,head2);
    else if(head1->data>head2->data)
        return intersect_lists(head1,head2->next);
    else{
        Node* temp = newnode(head1->data);
        temp->next = intersect_lists(head1->next,head2->next);
        return temp;
    }
}

Node* linear_search(Node* head, Node* tail, int x){
    for(Node* cur = head;cur!=tail;cur=cur->next){
        if(cur->data==x) return cur;
    }
    return NULL;
}

Node* bubble_sort(Node* head,Node* tail){
    for(Node* cur=tail;tail!=head->prev;tail=tail->prev)
        head=bubbleSwap(head,cur);
    return head;
}

Node* insertion_sort(Node* head, Node* tail){
    Node* sorted=NULL;
    for(Node* cur=head;cur!=tail->next;cur=cur->next)
        sorted=sortedInsert(sorted,cur->data);
    return sorted;
}

Node* selection_sort(Node* head,Node* tail){
    Node* minNode;
    for(Node* cur=head;cur!=tail->next;cur=cur->next){
        minNode = findMin(cur,tail);
        swap(cur->data,minNode->data);
    }
    return head;
}

Node* quick_sort(Node* head,Node* tail){
    if(head==NULL || head==tail || head==tail->next)
        return head;

    Node* pivot = tail;
    Node* j = head->prev;

    for(Node* cur=head;cur!=tail;cur=cur->next){
        if(cur->data<=pivot->data){
            j = (j==NULL)?head : j->next;
            swap(cur->data,j->data);
        }
    }
    j = (j==NULL)?head : j->next;
    swap(j->data,tail->data);
    head = quick_sort(head,j->prev);
    j->next = quick_sort(j->next,tail);
    return head;
}

Node* merge_sort(Node* head,Node* tail){
    if(head==NULL || head==tail || head==tail->next)
        return head;

    Node* slow=head;
    Node* fast=head;

    while(fast!=tail && fast->next!=tail){
        fast=fast->next->next;
        slow=slow->next;
    }

    Node* head1=head;
    Node* head2=slow->next;
    slow->next=NULL;

    head1 = merge_sort(head,slow);
    head2 = merge_sort(head2,tail);
    return merge_lists(head1,head2);
}

int main(){
    Node* head = NULL;
    head = push(head,3);
    head = push(head,9);
    head = push(head,5);
    head = push(head,7);
    head = push(head,1);

    Node* tail = head;
    while(tail->next){
        tail=tail->next;
    }

    //head=merge_sort(head,tail);

    Node* cur=head;
    while(cur){
        cout<<cur->data<<endl;
        cur=cur->next;
    }
    return 0;
}

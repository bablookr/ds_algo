#include <iostream>
#include <stack>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newnode(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/*Binary Search Tree: Miscellaneous
LCA,getLevel,minDistance*/

Node* LCA(Node* root,int n1,int n2){
    if(root==NULL) return root;
    if(root->data>n1 && root->data>n2)
        return LCA(root->left,n1,n2);
    if(root->data<n1 && root->data<n2)
        return LCA(root->right,n1,n2);
    return root;
}

int getLevel(Node* root,int data){
    if(root->data==data) return 0;
    else if(data<root->data) return 1+getLevel(root->left,data);
    return 1+getLevel(root->right,data);
}

int minDistance(Node* root,int a,int b){
    //Constraint: a<b
    if(root==NULL) return 0;
    if(root->data >a && root->data>b)
        return minDistance(root->left,a,b);
    if(root->data<a && root->data<b)
        return minDistance(root->right,a,b);
    if(a<=root->data && root->data<=b)
        return getLevel(root,a)+getLevel(root,b);
}

int main(){
    Node* root = newnode(4);
    root->left = newnode(1);
    root->right = newnode(7);
    root->right->left = newnode(6);

    cout<<minDistance(root,1,7)<<endl;

    return 0;
}

#include <iostream>
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

/*Binary Tree: Traversals
preorder, inorder, postorder,MorrisTraversal,getPostorder*/

void preorder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void MorrisTraversal(Node* root){
    if(root==NULL) return;
    Node* cur=root;
    while(cur){
        if(cur->left==NULL){
            cout<<cur->data<<" ";
            cur=cur->right;
        }
        else{
            Node* prev=cur->left;
            while(prev->right && prev->right!=cur)
                prev=prev->right;
            if(prev->right==NULL){
                prev->right=cur;
                cur=cur->left;
            }
            else{
                cout<<cur->data<<" ";
                prev->right=NULL;
                cur=cur->right;
            }
        }
    }
}

void getPostorder(int in[],int pre[],int n){
    int index=-1;
    for(int i=0;i<n;i++){
        if(in[i]==pre[0]){
            index = i; break;
        }
    }
    if(index!=0) getPostorder(in,pre+1,index);
    if(index!=n-1) getPostorder(in+index+1,pre+index+1,n-index-1);
    cout<<pre[0]<<" ";
}

int main(){
    Node* root = newnode(1);
    root->left = newnode(4);
    root->right = newnode(7);
    root->left->left = newnode(6);
    root->left->right = newnode(2);

    int n=6;
    int in[]={4,2,5,1,3,6};
    int pre[]={1,2,4,5,3,6};
    getPostorder(in,pre,n);

    return 0;
}

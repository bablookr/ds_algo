#include <iostream>
#include <queue>
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

/*Binary Search Tree: Basic functions
levelorder,ins,del,search_node*/

void levelorder(Node* root){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node* p = q.front(); q.pop();
            cout<<p->data<<" ";
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
        cout<<endl;
    }
}

Node* ins(Node* root, int data){
    if(root==NULL) return newnode(data);
    if(data<root->data)
        root->left = ins(root->left,data);
    else if(data>root->data)
        root->right = ins(root->right,data);
    return root;
}

Node* del(Node* root, int data){
    if(root==NULL) return NULL;
    if(data<root->data)
        root->left = del(root->left,data);
    else if(data>root->data)
        root->right = del(root->right,data);
    else{
        if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;
        Node* cur = root->right;
        while(cur->left) cur = cur->left;
        root->data = cur->data;
        root->right = del(root->right,cur->data);
    }
    return root;
}

Node* search_node(Node* root,int data){
    if(root==NULL) return NULL;
    if(data==root->data)
        return root;
    if(data<root->data)
        return search_node(root->left,data);
    else if(data>root->data)
        return search_node(root->right,data);
}

int main(){
    Node* root = NULL;
    root = ins(root, 4);
    root = ins(root, 1);
    root = ins(root, 7);
    root = ins(root, 6);
    //root = ins(root, 2);
    levelorder(root);

    return 0;
}

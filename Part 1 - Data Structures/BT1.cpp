#include <iostream>
#include <queue>
#include <vector>
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

/*Binary Tree: Basic functions
levelorder,printLevel,printDiagonals,printLeaves,printLeftBoundary,printRightBoundary,traverseBoundary,search_node*/

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

void printLevel(Node* root, int level){
    if(root==NULL) return;
    if(level==1) cout<<root->data<<" ";
    else{
        printLevel(root->left,level-1);
        printLevel(root->right,level-1);
    }
}

void printDiagonals(Node* root){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root); q.push(NULL);
    while(!q.empty()){
        if(q.front()){
            Node* p = q.front(); q.pop();
            while(p){
                cout<<p->data<<" ";
                if(p->left) q.push(p->left);
                p=p->right;
            }
        }
        else{
            q.pop();
            if(q.empty()) return;
            cout<<endl;
            q.push(NULL);
        }
    }
}

void printLeaves(Node* root){
    if(root==NULL) return;
    printLeaves(root->left);
    if(root->left==NULL && root->right==NULL) cout<<root->data<<" ";
    printLeaves(root->right);
}

void printLeftBoundary(Node* root){
    if(root==NULL) return;
    if(root->left){
        cout<<root->data<<" ";
        printLeftBoundary(root->left);
    }
    else if(root->right){
        cout<<root->data<<" ";
        printLeftBoundary(root->right);
    }
}

void printRightBoundary(Node* root){
    if(root==NULL) return;
    if(root->right){
        printRightBoundary(root->right);
        cout<<root->data<<" ";
    }
    else if(root->left){
        printRightBoundary(root->left);
        cout<<root->data<<" ";
    }
}

void traverseBoundary(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    printLeftBoundary(root->left);
    printLeaves(root->left);
    printLeaves(root->right);
    printRightBoundary(root->right);
}

Node* search_node(Node* root, int data){
    if(root==NULL) return NULL;
    if(data==root->data) return root;
    Node* ans = search_node(root->left,data);
    if(ans==NULL) return search_node(root->right,data);
    return ans;
}

int main(){
    Node* root = newnode(1);
    root->left = newnode(4);
    root->right = newnode(7);
    root->left->left = newnode(6);
    root->left->right = newnode(2);
    root->right->left=newnode(6);
    root->right->right=newnode(7);
    root->right->left->right = newnode(8);
    root->right->right->right = newnode(9);

    levelorder(root);
    traverseBoundary(root);

    return 0;
}

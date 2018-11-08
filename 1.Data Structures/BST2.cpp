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

/*Binary Search Tree: Range-related functions
isBST, printRange, countRange, removeRange,
inorder,inorderSuccessor,inorderPredecessor,minNode, maxNode,kthSmallest,BSTceil*/

bool isBST(Node* root, int mi, int ma){
    if(root==NULL) return true;
    if(mi<root->data && root->data<ma &&
        isBST(root->left,mi,root->data) &&
        isBST(root->right,root->data,ma)) return true;
    else return false;
}

void printRange(Node* root, int mi, int ma){
    if(root==NULL) return;
    if(root->data>mi)
        printRange(root->left,mi,ma);
    if(mi<=root->data && root->data<=ma)
        cout<<root->data<<" ";
    if(root->data<ma)
        printRange(root->right,mi,ma);
}

int countRange(Node* root, int mi, int ma){
    if(root==NULL) return 0;

    if(mi<=root->data && root->data<=ma)
        return countRange(root->left,mi,ma)+countRange(root->right,mi,ma);

    else if(root->data<mi)
        return countRange(root->right,mi,ma);

    else
        return countRange(root->left,mi,ma);
}

Node* removeOffRange(Node* root,int mi, int ma){
    if(root==NULL) return NULL;

    root->left = removeOffRange(root->left,mi,ma);
    root->right = removeOffRange(root->right,mi,ma);

    if(root->data<mi) return root->right;
    if(root->data>ma) return root->left;

    return root;
}

Node* maxNode(Node* root){
    Node* cur = root;
    while(cur->right) cur=cur->right;
    return cur;
}

Node* minNode(Node* root){
    Node* cur = root;
    while(cur->left) cur=cur->left;
    return cur;
}

int kthSmallest(Node* root,int k){
    int c=0, ans = -9999;
    Node* cur=root;
    while(cur){
        if(cur->left==NULL){
            c++; if(c==k) ans=cur->data;
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
                c++; if(c==k) ans=cur->data;
                prev->right=NULL;
                cur=cur->right;
            }
        }
    }
    return ans;
}

int BSTceil(Node* root,int key){
    if(root==NULL) return -1;
    if(root->data==key) return root->data;

    else if(root->data<key)
        return BSTceil(root->right,key);
    else{
        if(BSTceil(root->left,key)<key)
            return root->data;
        return BSTceil(root->left,key);
    }
}

int BSTfloor(Node* root,int key){
    if(root->left==NULL && root->right==NULL && root->data>key)
        return -1;
    if(root->data<=key && root->right==NULL)
        return root->data;
    if(root->data<=key && root->right->data>key)
        return root->data;
    if(root->data>=key)
        return BSTfloor(root->left,key);
    else
        return BSTfloor(root->right,key);
}

Node* inorderSuccessor(Node* root, Node* node){
    if(node->right) return minNode(node->right);
    Node* cur=root;
    Node* temp = NULL;
    while(cur!=node){
        if(node->data<root->data){
            temp=cur; cur=cur->left;
        }
        else if(node->data>root->data){
            cur=cur->right;
        }
    }
    return temp;
}

Node* inorderPredecessor(Node* root, Node* node){
    if(node->left) return maxNode(node->left);
    Node* cur = root;
    Node* temp = NULL;
    while(cur!=node){
        if(node->data>root->data){
            temp = cur; cur=cur->right;
        }
        else if(node->data<root->data){
            cur=cur->left;
        }
    }
    return temp;
}

void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node* root = newnode(4);
    root->left = newnode(1);
    root->right = newnode(7);
    root->right->left = newnode(6);

    inorder(root); cout<<endl;
    if(isBST(root,-1000,1000)) cout<<"Yes"<<endl;

    return 0;
}

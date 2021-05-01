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

/*Binary Search Tree: Conversions and preorder functions
Array2BST, LL2BST, DLL2BST,preorderBST,pre2BST,pre2BSTleaves*/

Node* Array2BST(int a[],int l,int h){
    //Constraint: Array should be sorted.
    if(l>h) return NULL;

    int mid=(l+h)/2;
    Node* root=newnode(a[mid]);

    root->left=Array2BST(a,l,mid-1);
    root->right=Array2BST(a,mid+1,h);

    return root;

}

Node* LL2BST(Node** ptr, int n){
    //Constraint: LinkedList (with right pointer) should be sorted.
    if(n<=0) return NULL;
    Node* left = LL2BST(ptr,n/2);

    Node* root = newnode((*ptr)->data);
    root->left = left;
    (*ptr) = (*ptr)->right;

    root->right = LL2BST(ptr,n-n/2-1);
    return root;
}

Node* DLL2BST(Node** ptr, int n){
    //Constraint: DLL (with left/right pointers) should be sorted.
    if(n<=0) return NULL;
    Node* left = DLL2BST(ptr,n/2);

    Node* root = *ptr;
    root->left = left;
    (*ptr) = (*ptr)->right;

    root->right = DLL2BST(ptr,n-n/2-1);
    return root;
}

bool preorderBST(int pre[],int n){
    stack<int> stk;
    int root=-9999;
    for(int i=0;i<n;i++){
        if(pre[i]<root) return false;
        while(!stk.empty() && stk.top()<pre[i]){
            root = stk.top(); stk.pop();
        }
        stk.push(pre[i]);
    }
    return true;
}

Node* pre2BST(int pre[],int n){
    stack<Node*> stk;
    Node* root = newnode(pre[0]);
    stk.push(root);
    for(int i=1;i<n;i++){
        Node* top = NULL;
        while(!stk.empty() && stk.top()->data<pre[i]){
            top = stk.top(); stk.pop();
        }
        if(top){
            top->right = newnode(pre[i]);
            stk.push(top->right);
        }
        else{
            stk.top()->left = newnode(pre[i]);
            stk.push(stk.top()->left);
        }
    }
    return root;
}

void pre2BSTleaves(int pre[],int n){
    stack<int> stk;
    for(int i=0,j=1;j<n;i++,j++){
        bool flag=false;
        if(pre[i]>pre[j]) stk.push(pre[i]);
        else{
            while(!stk.empty() && stk.top()<pre[j]){
                stk.pop();
                flag=true;
            }
            if(flag) cout<<pre[i]<<" ";
        }
    }
    cout<<pre[n-1]<<endl;
}

void preorder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int n = 6;
    int pre[] = {10, 5, 1, 7, 40, 50};
    Node* root = pre2BST(pre,n);
    preorder(root);
    return 0;
}

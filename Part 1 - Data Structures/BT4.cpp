#include <iostream>
#include <stack>
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

/*Binary Tree: Miscellaneous
printPaths,getPath,getAncestors,LCA,getLevel,minDistance*/

void printPaths(Node* root,vector<int> &path){
    if(root==NULL) return;
    path.push_back(root->data);
    if(root->left==NULL && root->right==NULL){
        for(int i=0;i<path.size();i++) cout<<path[i]<<" ";
        cout<<endl;
    }
    printPaths(root->left,path);
    printPaths(root->right,path);
    path.pop_back();
}

bool getPath(Node* root, vector<int> &path, int x){
    if(root==NULL) return false;
    path.push_back(root->data);
    if(root->data==x) return true;
    if(getPath(root->left,path,x) || getPath(root->right,path,x)) return true;
    path.pop_back();
    return false;
}

bool getAncestors(Node* root,vector<int> &path,int x){
    if(root==NULL) return false;
    if(root->data==x) return true;
    if(getAncestors(root->left,path,x) || getAncestors(root->right,path,x)){
        path.push_back(root->data);
        return true;
    }
    return false;
}

Node* LCA(Node* root,int n1,int n2){
    if(root==NULL) return NULL;
    if(root->data==n1 || root->data==n2) return root;

    Node* leftLCA = LCA(root->left,n1,n2);
    Node* rightLCA = LCA(root->right,n1,n2);

    if(leftLCA && rightLCA) return root;
    if(leftLCA) return leftLCA;
    return rightLCA;
}

int getLevel(Node* root, int data, int root_level){
    if(root==NULL) return -1;
    if(data==root->data) return root_level;
    int ans = getLevel(root->left,data,root_level+1);
    if(ans==-1) return getLevel(root->right,data,root_level+1);
    return ans;
}

int minDistance(Node* root,int n1,int n2){
    Node* lca = LCA(root,n1,n2);
    return getLevel(lca,n1,0)+getLevel(lca,n2,0);
}

int main(){
    Node* root = newnode(1);
    root->left = newnode(4);
    root->right = newnode(7);
    root->left->left = newnode(6);
    root->left->right = newnode(2);
    root->right->left=newnode(6);
    root->right->right=newnode(7);
    root->left->left->left=newnode(8);

    vector<int> path;
    if(getAncestors(root,path,8)){
        for(int i=0;i<path.size();i++) cout<<path[i]<<" ";
    }
    return 0;
}

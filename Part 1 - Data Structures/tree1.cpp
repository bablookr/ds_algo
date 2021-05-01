#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*n-ary Tree: Basics
newnode, levelOrder*/

struct Node{
    int data;
    vector<Node*> child;
};

Node* newnode(int data){
    Node* temp=new Node();
    temp->data=data;
    return temp;
}

void levelorder(Node* root){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node* p=q.front(); q.pop();
            cout<<p->data<<" ";
            for(int i=0;i<p->child.size();i++)
                q.push(p->child[i]);
        }
        cout<<endl;
    }
}

int main(){
    Node* root=newnode(10);
    (root->child).push_back(newnode(2));
    (root->child).push_back(newnode(34));
    (root->child).push_back(newnode(56));
    (root->child).push_back(newnode(100));
    (root->child[2]->child).push_back(newnode(1));
    (root->child[3]->child).push_back(newnode(7));
    (root->child[3]->child).push_back(newnode(8));
    (root->child[3]->child).push_back(newnode(9));

    levelorder(root);

    return 0;
}

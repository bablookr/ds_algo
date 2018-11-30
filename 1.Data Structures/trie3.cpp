#include <iostream>
using namespace std;

struct Node{
    Node* child[26];
};

Node* newnode(){
    Node* temp = new Node();
    for(int i=0;i<26;i++) temp->child[i] = NULL;
    return temp;
}

/*Trie: Application
Distinct substrings*/

void insertKey(Node* root,string key){
    if(key.length()==0) return;
    int i = key[0]-'a';
    if(root->child[i]==NULL) root->child[i] = newnode();
    insertKey(root->child[i],key.substr(1));
}

int countNodes(Node* root){
    if(root==NULL) return 0;
    int c = 1;
    for(int i=0;i<26;i++){
        if(root->child[i]) c+=countNodes(root->child[i]);
    }
    return c;
}

int main(){
    string str = "ababa";
    Node* root = newnode();
    for(int i=0;i<str.length();i++) insertKey(root,str.substr(i));
    cout<<countNodes(root)<<endl;
    return 0;
}

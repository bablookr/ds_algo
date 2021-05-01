#include <iostream>
using namespace std;

struct Node{
    bool isLeaf;
    Node* child[26];
};

Node* newnode(){
    Node* temp = new Node();
    temp->isLeaf = false;
    for(int i=0;i<26;i++) temp->child[i] = NULL;
    return temp;
}

/*Trie: Application
Longest Common Prefix*/

void insertKey(Node* root,string key){
    Node* cur = root;
    for(int l=0;l<key.length();l++){
        int i = key[l]-'a';
        if(cur->child[i]==NULL) cur->child[i] = newnode();
        cur = cur->child[i];
    }
    cur->isLeaf = true;
}

string LCP(Node* root){
    string prefix;
    Node* cur = root;
    while(cur->isLeaf==false){
        int index, c = 0;
        for(int i=0;i<26;i++){
            if(cur->child[i]){
                index = i; c++;
            }
        }
        if(c!=1) break;
        cur = cur->child[index];
        prefix.push_back('a'+index);
    }
    return prefix;
}

int main(){
    int n = 4;
    string keys[] = {"geeksforgeeks", "geeks",
                    "geek", "geezer"};

    Node* root = newnode();
    for(int i=0;i<n;i++) insertKey(root,keys[i]);
    cout<<LCP(root);
    return 0;
}


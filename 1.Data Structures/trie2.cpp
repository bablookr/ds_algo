#include <iostream>
#include <vector>
using namespace std;

struct Node{
    vector<int> pos;
    Node* child[250];
};

Node* newnode(){
    Node* temp = new Node();
    for(int i=0;i<250;i++) temp->child[i] = NULL;
    return temp;
}

/*Trie: Applications
Pattern Searching*/

void insertKey(Node* root,string key,int index){
    (root->pos).push_back(index);
    if(key.length()==0) return;
    int i = key[0];
    if(root->child[i]==NULL) root->child[i] = newnode();
    insertKey(root->child[i],key.substr(1),index+1);
}

vector<int> searchKey(Node* root,string key){
    if(key.length()==0) return root->pos;
    int i = key[0];
    if(root->child[i]==NULL) return {};
    return searchKey(root->child[i],key.substr(1));
}

int main(){
    string str = "geeksforgeeks.org";
    Node* root = newnode();
    for(int i=0;i<str.length();i++) insertKey(root,str.substr(i),i);

    string key = "geek";
    vector<int> ans = searchKey(root,key);
    for(int i=0;i<ans.size();i++) cout<<ans[i]-key.length()<<endl;

    return 0;
}

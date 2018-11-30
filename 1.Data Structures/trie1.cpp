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


/*Trie: Basic Functions
insertKey,searchKey,deleteKey,printKeys*/

void insertKey(Node* root,string key){
    Node* cur = root;
    for(int l=0;l<key.length();l++){
        int i = key[l]-'a';
        if(cur->child[i]==NULL) cur->child[i] = newnode();
        cur = cur->child[i];
    }
    cur->isLeaf = true;
}

bool searchKey(Node* root,string key){
    Node* cur = root;
    for(int l=0;l<key.length();l++){
        int i = key[l]-'a';
        if(cur->child[i]==NULL) return false;
        cur = cur->child[i];
    }
    return (cur && cur->isLeaf);
}

/*bool deleteKey(Node* root,string key,int level){
    if(root==NULL) return false;
    if(level==key.length()){
        if(!root->isLeaf){
            root->isLeaf = true;
            if(isFreeNode(root)) return true;
            return false;
        }
    }
    int i = key[level]-'a';
    if(deleteKey(root->child[i],key,level+1)){
        delete root->child[i];
        return (!root->isLeaf && isFreeNode(root));
    }
    return false;
}*/

void printKeys(Node* root,char str[],int level){
    if(root->isLeaf){
        str[level] = '\0';
        cout<<str<<endl;
    }
    for(int i=0;i<26;i++){
        if(root->child[i]){
            str[level] = 'a'+i;
            printKeys(root->child[i],str,level+1);
        }
    }
}

int main(){
    int n = 8;
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };

    Node* root = newnode();
    for(int i=0;i<n;i++) insertKey(root,keys[i]);
    //deleteKey(root,keys[0],0);
    //if(searchKey(root,"the")) cout<<"Found"<<endl;
    char str[20];
    printKeys(root,str,0);
    return 0;
}

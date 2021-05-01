#include <iostream>
#include <cmath>
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

/*Binary Tree: int returns
Count,leafCount,sum,Max,height,diameter,minDepth*/

int Count(Node* root){
    if(root==NULL) return 0;
    return Count(root->left)+Count(root->right)+1;
}

int leafCount(Node* root){
    if(root==NULL) return 0;
    if(root->left==NULL || root->right==NULL) return 1;
    return leafCount(root->left)+leafCount(root->right);
}

int nonLeafCount(Node* root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return 0;
    return 1+nonLeafCount(root->left)+nonLeafCount(root->right);
}

int sum(Node* root){
    if(root==NULL) return 0;
    return root->data+sum(root->left)+sum(root->right);
}

int Max(Node* root){
    if(root==NULL) return -9999;
    return max(root->data,max(Max(root->left),Max(root->right)));
}

int height(Node* root){
    if(root==NULL) return 0;

    int lheight=height(root->left);
    int rheight=height(root->right);

    return max(lheight,rheight)+1;
}

int diameter(Node* root){
    if(root==NULL) return 0;

    int lheight=height(root->left);
    int rheight=height(root->right);

    int ldiameter=diameter(root->left);
    int rdiameter=diameter(root->right);

    return max(lheight+rheight+1,max(ldiameter,rdiameter));
}

int minDepth(Node* root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return 1;
    if(root->left==NULL) return minDepth(root->right)+1;
    if(root->right==NULL) return minDepth(root->left)+1;
    return min(minDepth(root->left),minDepth(root->right))+1;
}

/*Binary Tree: bool returns
areSame,areSimilar,areImages,areSimilarImages,areIsomorphic,isSubtree,
isBalanced,hasCSP,isSumTree,isSymmetric,isFoldable,isContinuous,hasPathsum*/

bool areSame(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL)
        return true;
    if(root1==NULL || root2==NULL)
        return false;
    return(root1->data==root2->data && areSame(root1->left,root2->left) && areSame(root1->right,root2->right));
}

bool areSimilar(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL)
        return true;
    if(root1==NULL || root2==NULL)
        return false;
    return areSimilar(root1->left,root2->left) && areSimilar(root1->right,root2->right);
}

bool areImages(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL)
        return true;
    if(root1==NULL || root2==NULL)
        return false;
    return root1->data==root2->data && areImages(root1->left,root2->right) && areImages(root1->right,root2->left);
}

bool areSimilarImages(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL)
        return true;
    if(root1==NULL || root2==NULL)
        return false;
    return areSimilarImages(root1->left,root2->right) && areSimilarImages(root1->right,root2->left);
}

bool areIsomorphic(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL)
        return true;
    if(root1==NULL || root2==NULL)
        return false;
    if(root1->data!=root2->data)
        return false;
    return (areIsomorphic(root1->left,root2->left) && areIsomorphic(root1->right,root2->right)) ||
            (areIsomorphic(root1->left,root2->right) && areIsomorphic(root1->right,root2->left));
}

bool isSubtree(Node* root,Node* sroot){
    if(sroot==NULL)
        return true;
    if(root==NULL)
        return false;
    if(areSame(root,sroot))
        return true;
    return isSubtree(root->left,sroot)||isSubtree(root->right,sroot);
}

bool isBalanced(Node* root){
    if(root==NULL)
        return true;
    if(abs(height(root->left)-height(root->right))<=1 &&
    isBalanced(root->left) && isBalanced(root->right))
        return true;
    else
        return false;
}

bool hasCSP(Node* root){
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return true;
    int ldata=0,rdata=0;
    if(root->left)
        ldata=root->left->data;
    if(root->right)
        rdata=root->right->data;
    if(root->data==root->left->data+root->right->data && hasCSP(root->left) && hasCSP(root->right))
        return true;
    else
        return false;
}

bool isSumtree(Node* root){
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return true;
    if(root->data==sum(root->left)+sum(root->right) &&
    isSumtree(root->left) && isSumtree(root->right))
        return true;
    return false;
}

bool isSymmetric(Node* root){
    if(root==NULL) return true;
    return areImages(root,root);
}

bool isFoldable(Node* root){
    if(root==NULL) return true;
    return areSimilarImages(root->left,root->right);
}

bool isContinuous(Node* root){
    if(root==NULL) return true;
    if(root->left==NULL && root->right==NULL) return true;
    if(root->left==NULL)
        return isContinuous(root->right) && (abs(root->data-root->right->data)==1);
    if(root->right==NULL)
        return isContinuous(root->left) && (abs(root->data-root->left->data)==1);
    return isContinuous(root->right) && isContinuous(root->left) &&
            (abs(root->data-root->left->data)==1) && (abs(root->data-root->right->data)==1);
}

bool hasPathsum(Node* root,int sum){
    if(root==NULL)
        return(sum==0);
    if(root->left==NULL && root->right==NULL)
        return(sum==root->data);
    bool ans=false;
    if(root->left)
        ans=ans||hasPathsum(root->left,sum-root->data);
    if(root->right)
        ans=ans||hasPathsum(root->right,sum-root->data);
    return ans;
}

void Mirror(Node* root){
    if(root==NULL) return;
    Mirror(root->left);
    Mirror(root->right);
    swap(root->left->data,root->right->data);
}

int main(){
    Node* root = newnode(1);
    root->left = newnode(4);
    root->right = newnode(7);
    root->left->left = newnode(6);
    root->left->right = newnode(2);

    cout<<sum(root)<<endl;
    if(isBalanced(root)) cout<<"Balanced"<<endl;

    return 0;
}

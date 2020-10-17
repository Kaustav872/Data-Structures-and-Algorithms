#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<stack>
#include<string.h>
#include<unordered_map>
#include<map>
#include<climits>
using namespace std;

struct Node {
  Node* left;
  Node* right;
  int data;
};

Node* newNode(int key)
{
  Node* node=new Node();
  node->left=node->right=NULL;
  node->data=key;

  return node;
}

void mirror(Node* root)
{
  if(root==NULL)
    return;

  else {
    struct Node* temp;
    mirror(root->left);
    mirror(root->right);

    temp=root->left;
    root->left=root->right;
    root->right=temp;
  }
}

void inorder(Node* root)
{
  if(root==NULL)
    return;

  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

int main()
{

  Node* root=newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);

  cout<<"Before mirror"<<endl;
  inorder(root);
  cout<<endl;
  cout<<"After mirror"<<endl;
  mirror(root);
  inorder(root);

}

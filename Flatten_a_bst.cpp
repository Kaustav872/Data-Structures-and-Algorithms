#include<bits/stdc++.h>
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

void inorder(Node* root,Node* &prev)
{
  if(root==NULL)
    return;

  inorder(root->left,prev);
  prev->left=NULL;
  prev->right=root;
  prev=root;
  inorder(root->right,prev);
}

Node* flatten_BST(Node* root)
{
  if(root==NULL)
    return 0;

  Node* prev=newNode(-1);

  Node* dummy=prev;

  inorder(root,prev);
  prev->left=NULL;
  prev->right=NULL;
  Node* ret=dummy->right;

  delete dummy;
  return ret;
}
void print(Node* parent)
{
  Node* curr=parent;
  while(curr !=NULL)
  {
    cout<<curr->data<<" ";
    curr=curr->right;
  }
}

int main()
{
  /*                          1
                       2               3
                  4        5        6      7
  */

  Node* root = newNode(5);
  root->left = newNode(3);
  root->right = newNode(7);
  root->left->left = newNode(2);
  root->left->right = newNode(4);
  root->right->left = newNode(6);
  root->right->right = newNode(8); 
    /* vector initializatio to store the inorder traversal of the whole tree
    */

    print(flatten_BST(root));

    return 0;


}

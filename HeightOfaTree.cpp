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

int Height(Node* root)
{
  if(root==NULL)
    return 0;

  int lheight=Height(root->left);
  int rheight=Height(root->right);

  if(lheight>rheight)
  {
    return lheight+1;
  }
  else
  {
    return rheight+1;
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
  root->left=newNode(2);
  root->right=newNode(3);
  root->left->left=newNode(4);
  root->left->left->right=newNode(5);
  cout<<Height(root);

}

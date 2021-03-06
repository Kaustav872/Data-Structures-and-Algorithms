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

int height(Node* root)
{
  if(root==NULL)
    return 0;

  int lheight=height(root->left);
  int rheight=height(root->right);
  if(lheight>rheight)
  {
      return 1+lheight;
  }
  else {
    return 1+rheight;
  }
}

int diameter(Node* root)
{
  if(root==NULL)
    return 0;

  int llheight=height(root->left);
  int rrheight=height(root->right);

  int ldiameter=diameter(root->left);
  int rdiameter=diameter(root->right);

  int result=max(llheight+rrheight+1,max(ldiameter,rdiameter));
  return result;

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

  cout<<diameter(root);

}

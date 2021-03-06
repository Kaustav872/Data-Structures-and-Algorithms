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


void zig_zag(Node* root)
{
  if(root==NULL)
    return;

  stack<struct Node* > currentlevel;
  stack<struct Node*> nextlevel;
  currentlevel.push(root);
  bool leftorright=true;
  while(!currentlevel.empty())
  {
    struct Node* temp=currentlevel.top();
    currentlevel.pop();
    if(temp)
    {
      cout<<temp->data<<" ";
    }

    if(leftorright)
    {
      if(temp->left)
      {
        nextlevel.push(temp->left);
      }
      if(temp->right)
      {
        nextlevel.push(temp->right);
      }
    }
    else
    {
      if(temp->right)
      {
        nextlevel.push(temp->right);
      }
      if(temp->left)
      {
        nextlevel.push(temp->left);
      }
    }

    if(currentlevel.empty())
    {
      leftorright=!leftorright;
      swap(currentlevel,nextlevel);
    }

  }


}

int main()
{
  /*                          1
                       2               3
                  4        5        6      7
  */

    Node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    zig_zag(root);



}

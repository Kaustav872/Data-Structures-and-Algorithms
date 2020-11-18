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

void left_print(Node* root)
{
  if(root==NULL)
    return;


  queue<Node*> q;
  q.push(root);
  while(!q.empty())
  {
    Node* temp=q.front();
    if(temp->left==NULL && temp->right==NULL)
      return;
    cout<<temp->data<<" ";
    q.pop();
    if(temp->left)
    {
      q.push(temp->left);
    }
  }
}
void right_print(Node* root)
{
  if(root==NULL)
    return;

  queue<Node*> q;
  q.push(root);
  stack<int> s;
  int count=0;
  while(!q.empty())
  {
    Node* temp=q.front();
    s.push(temp->data);
    // count++;
    q.pop();
    if(temp->right)
    {
      q.push(temp->right);
    }
  }
  while(!s.empty())
  {
    count++;

    int temp=s.top();
    if(count!=1)
    {
    cout<<temp<<" ";
    }

    s.pop();
  }
}

void leaf_print(Node* root)
{
  if(root==NULL)
    return;


  if(root->left==NULL && root->right==NULL)
    cout<<root->data<<" ";

  else
  {
    leaf_print(root->left);
    leaf_print(root->right);
  }
}


int main()
{
  // /*                          1
  //                      2               3
  //                 4        5        6      7
  // */
  //
  //   Node* root = NULL;
  //   root = newNode(1);
  //   root->left = newNode(2);
  //   root->right = newNode(3);
  //   root->left->left = newNode(4);
  //   root->left->right = newNode(5);
  //   root->right->left = newNode(6);
  //   root->right->right = newNode(7);

    Node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);

    left_print(root);
    leaf_print(root);
    right_print(root->right);
}

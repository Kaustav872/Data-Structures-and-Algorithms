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
void preorder(Node* root)
{

  stack<Node*> s;
  s.push(root);
  while(!s.empty())
  {
    Node* temp=s.top();
    cout<<temp->data<<" ";
    s.pop();
    if(temp->right)
    {
      s.push(temp->right);
    }
    if(temp->left)
    {
      s.push(temp->left);
    }
  }

}

int main()
{

  Node* root=newNode(1);
  root->left=newNode(2);
  root->right=newNode(3);
  root->left->left=newNode(4);
  root->left->left->right=newNode(5);
  preorder(root);

}

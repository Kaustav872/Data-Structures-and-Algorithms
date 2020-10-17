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
void inorder(Node* root)
{

  stack<Node*> s;
  Node* curr=root;
  while(curr !=NULL || s.empty()==false)
  {
    while(curr !=NULL)
    {
      s.push(curr);
      curr=curr->left;
    }
    curr=s.top();
    s.pop();
    cout<<curr->data<<" ";
    curr=curr->right;
  }

}

int main()
{

  Node* root=newNode(1);
  root->left=newNode(2);
  root->right=newNode(3);
  root->left->left=newNode(4);
  root->left->left->right=newNode(5);
  inorder(root);

}

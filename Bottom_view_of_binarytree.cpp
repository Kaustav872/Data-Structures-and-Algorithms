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
  int hd;
};

Node* newNode(int key)
{
  Node* node=new Node();
  node->left=node->right=NULL;
  node->data=key;

  return node;
}


void topview(Node* root)
{
  if(root==NULL)
    return;
  queue<Node*> q;
  map<int,int> m;

  int hd=0;
  root->hd=hd;
  q.push(root);
  while(!q.empty())
  {
    hd=root->hd;
    // if(m.count(hd)==0)
    // {
      m[hd]=root->data;
    // }
    if(root->left)
    {
      root->left->hd=hd-1;
      q.push(root->left);
    }
    if(root->right)
    {
      root->right->hd=hd+1;
      q.push(root->right);
    }
    q.pop();
    root=q.front();
  }


  for(auto i=m.begin();i!=m.end();i++)
  {
    cout<<i->second<<" ";
  }
}

int main()
{
  /*                          1
                       2               3
                  4        5        6      7
  */

    // Node* root = NULL;
    // root = newNode(1);
    // root->left = newNode(2);
    // root->right = newNode(3);
    // root->left->left = newNode(4);
    // root->left->right = newNode(5);
    // root->right->left = newNode(6);
    // root->right->right = newNode(7);

    Node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(5);
    root->left->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(25);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    topview(root);



}

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

void ReverselevelOrder(Node* root)
{
  if(root==NULL)
    return;

  queue<Node*> q;
  vector<int> result;
  q.push(root);
  while(!q.empty())
  {
    Node* temp =q.front();
    result.push_back(temp->data);
    // cout<<temp->data<<" ";
    q.pop();
    if(temp->left)
    {
      q.push(temp->left);
    }
    if(temp->right)
    {
      q.push(temp->right);
    }
  }
  reverse(result.begin(),result.end());
  for(int i=0;i<result.size();i++)
  {
    cout<<result[i]<<" ";
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
  ReverselevelOrder(root);

}

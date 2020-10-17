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
void postorder(Node* root)
{

  stack<Node*> s;
  s.push(root);
  stack<Node*> s1;
  while(!s.empty())
  {
    Node* temp=s.top();
    s.pop();
    s1.push(temp);

    if(temp->left)
    {
      s.push(temp->left);
    }
    if(temp->right)
    {
      s.push(temp->right);
    }
  }

  while(!s1.empty())
  {
    Node * temp_result=s1.top();
    s1.pop();
    cout<<temp_result->data<<" ";
  }

}
void recpostorder(Node* root)
{
  if(root==NULL)
    return;

  recpostorder(root->left);
  recpostorder(root->right);
  cout<<root->data<<" ";
}

int main()
{

    Node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
  cout<<"Post order traversal using iterative approach: "<<endl;
  postorder(root);
  cout<<endl;
  cout<<"PostOrder traversal using simple recursion: "<<endl;
  recpostorder(root);


}

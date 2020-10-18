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

void levelprint(Node* root,int level,int *max_level)
{
  if(root==NULL)
    return;

  if(*max_level<level)
  {
    cout<<root->data<<" ";
    *max_level=level;
  }


  levelprint(root->right,level+1,max_level);
  levelprint(root->left,level+1,max_level);


}
void leftview(Node* root)
{
  int max_level=0;
  levelprint(root,1,&max_level);

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
    leftview(root);



}

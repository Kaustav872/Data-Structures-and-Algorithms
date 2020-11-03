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


void DiagonalPrintUtil(Node* root)
{
  if(root==NULL)
    return;
}

void diagonalPrintUtil(Node* root,int d,map<int,vector<int>> &diagonalPPrint)
{
  if(root==NULL)
    return;
  diagonalPPrint[d].push_back(root->data);

  diagonalPrintUtil(root->left,d+1,diagonalPPrint);

  diagonalPrintUtil(root->right,d,diagonalPPrint);

}


void DiagonalPrint(Node* root)
{
  map<int,vector<int>> diagonalPPrint;
  diagonalPrintUtil(root,0,diagonalPPrint);

  cout<<"Diagonal Print: "<<endl;
  for(auto it: diagonalPPrint)
  {
    vector<int> v=it.second;
    for(auto it: v)
    {
      cout<<it<<" ";
    }
    cout<<endl;
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

    DiagonalPrint(root);



}

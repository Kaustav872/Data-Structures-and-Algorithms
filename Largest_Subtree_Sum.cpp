#include<bits/stdc++.h>
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

int Largest_SubTree_SumUtil(Node* root,int &ans)
{
  if(root==NULL)
    return 0;

  int currAns=root->data + Largest_SubTree_SumUtil(root->left,ans) + Largest_SubTree_SumUtil(root->right,ans);

  ans = max(ans,currAns);

  return currAns;
}

int Largest_SubTree_Sum(Node* root)
{
  if(root==NULL)
    return 0;

  int ans=INT_MIN;

  Largest_SubTree_SumUtil(root,ans);

  return ans;
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
    /* vector initializatio to store the inorder traversal of the whole tree
    */

    cout<<Largest_SubTree_Sum(root);



}

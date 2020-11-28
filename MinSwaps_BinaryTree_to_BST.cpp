#include<bits/stdc++.h>
using namespace std;

struct Node {
  Node* left;
  Node* right;
  int data;
};
vector<int> in;
Node* newNode(int key)
{
  Node* node=new Node();
  node->left=node->right=NULL;
  node->data=key;

  return node;
}


void inorder(Node* root)
{
  if(root==NULL)
    return;


  inorder(root->left);
  in.push_back(root->data);

  inorder(root->right);
}


int min_swapsa(vector<int> in,int c)
{
  pair<int,int> arr[c];

  for(int i=0;i<c;i++)
  {
    arr[i].first=in[i];
    arr[i].second=i;
  }

  sort(arr,arr+c);
  vector<bool> vis(c,false);

  int ans=0;

  for(int i=0;i<c;i++)
  {
    if(vis[i] || arr[i].second==i)
    {
      continue;
    }

    int cycle_size=0;
    int j=i;
    while (!vis[j])
    {
      vis[j]=1;

      j=arr[j].second;
      cycle_size++;

    }

    if(cycle_size>0)
    {
      ans+=(cycle_size-1);
    }
  }
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

    inorder(root);

    int count=in.size();
    // cout<<count<<endl;
    cout<<min_swapsa(in,count);



}

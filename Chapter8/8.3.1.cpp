#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define bool int
using namespace std;
struct tNode
{
   int data;
   struct tNode* left;
   struct tNode* right;
};
ostream& operator<<(ostream& os, struct tNode *root)  
{  
     struct tNode *current,*pre;
 
  if(root == NULL)
     return os; 
  current = root;
  while(current != NULL)
  {                 
    if(current->left == NULL)
    {
      printf("%d ", current->data);
      current = current->right;      
    }    
    else
    {
      pre = current->left;
      while(pre->right != NULL && pre->right != current)
        pre = pre->right;
      if(pre->right == NULL)
      {
        pre->right = current;
        current = current->left;
      }
      else 
      {
        pre->right = NULL;
        printf("%d ",current->data);
        current = current->right;      
      } 
    } 
  }
    return os;  
}  
struct tNode* newtNode(int data)
{
  struct tNode* tNode = (struct tNode*)
                       malloc(sizeof(struct tNode));
  tNode->data = data;
  tNode->left = NULL;
  tNode->right = NULL;
 
  return(tNode);
}

int main()
{ int rooty, lefty, righty;
  cout<<"Provide three nodes of binary tree in order: root, left child, right child"<<endl;
  cout<<"root:"<<endl;
  cin >> rooty;
  cout<<"left:"<<endl;
  cin >> lefty;
  cout<<"right:"<<endl;
  cin >> righty;
  struct tNode *root = newtNode(rooty);
  root->left = newtNode(lefty);
  root->right  = newtNode(righty);
  cout << root;
  return 0;
}
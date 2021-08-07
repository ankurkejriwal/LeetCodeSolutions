#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <vector>

//g++ -std=c++11 .cpp -o      

using namespace std;

struct node {
    int data;
    struct node *left, *right;
};
 
// function to create a new node of tree and returns pointer
struct node* newNode(int data);

struct node* newNode(int data)
{
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

int solve (node* root, int &result){
  if(root ==  nullptr){
    return 0;
  }
  int left = solve (root->left,result);
  int right = solve (root->right, result);

  int temp = max(root->data+ max(left,right),root->data);
  int ans = max(temp,root->data+left+right);
  result = max(ans,result);

  return temp;
}

// Driver Code
int main()
{
    /* Constructed binary tree is
            1
            / \
        2     3
        / \
    4     5
    */
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int res = INT_MIN;
    int temp = solve(root,res);
    cout<<res<<endl;

}
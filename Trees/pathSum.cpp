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

bool solve(node* root,int targetSum){
    if(root == nullptr){
        return false;
    }
    if (root->data == targetSum && root->left ==  nullptr && root->right ==nullptr){
        return true;
    }
    if (root->data != targetSum && root->left == nullptr && root->right == nullptr){
        return false;
    }
    int left = solve(root->left,targetSum-root->data);
    int right = solve (root->right,targetSum-root->data);

    return(left || right);
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

    cout<<solve(root,4)<<endl;

}
#include<bits/stdc++.h>
using namespace std;
struct node{
    int key;
    node* left;
    node* right;

    node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};
void inorder(node* root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

node* insert_recursive(node* root,int val)
{
    if(root==NULL)
    {
        return new node(val);
    }
    else if(root->key > val)
    {
        root->left = insert_recursive(root->left,val);
    }
    else if(root->key < val)
    {
        root->right = insert_recursive(root->right,val);
    }
    
    return root;
}

node* iter_insert(node* root,int x)
{
    node* temp = new node(x);
    node* parent = NULL;
    node* curr = root;

    while(curr!=NULL)
    {
        parent=curr;
        if(curr->key < x)
        {
            curr=curr->right;
        }
        else if(curr->key > x)
        {
            curr = curr->left;
        }
        else
            return root;
    }
    if(parent==NULL)
    {
        return temp;
    }
    if(parent->key < x)
    {
        parent->right = temp;
    }
    else
    {
        parent->left = temp;
    }
    return root;
}

int main()
{
    node* root = new node(15);
    root->left = new node(5);
    root->left->left = new node(3);
    root->right = new node(20);
    root->right->left = new node(18);
    root->right->left->left = new node(16);
    root->right->right = new node(80);
    inorder(root);
    cout<<endl;
    insert_recursive(root,2);
    iter_insert(root,200);
    inorder(root);
     
    return 0;
}

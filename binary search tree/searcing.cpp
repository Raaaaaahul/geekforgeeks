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

bool search(node* root,int val)
{
    if(root==NULL)
    {
        return false;
    }
    else if(root->key == val)
    {
        return true;
    }
    else if(root->key > val)
    {
        return search(root->left,val);
    }
    else
    {
        return search(root->right,val);
    }
}
bool iterSearch(node* root,int val)
{
    while(root!=NULL)
    {
        if(root->key==val)
        {
            return true;
        }
        else if(root->key>val)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return false;
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

    cout<<search(root,16)<<endl;
    cout<<iterSearch(root,18)<<endl;
    return 0;
}
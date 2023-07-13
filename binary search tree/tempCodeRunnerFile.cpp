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
node* floorBst(node* root,int x)
{
    node* res = NULL;
    while(root!=NULL)
    {
        if(root->key==x)
        {
            return root;
        }
        else if(root->key >  x)
        {
            root = root->left;
        }
        else
        {
            res = root;
            root= root->right;
        }
    }
    return res;
}

node* ceilBst(node* root,int x)
{
    node* res = NULL;
    while(root!=NULL)
    {
        if(root->key==x)
        {
            return root;
        }
        else if(root->key < x)
        {
            root = root->right;
        }
        else
        {
            res = root;
            root = root->left;
        }
    }
    return res;
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


    node* ans = floorBst(root,23);
    cout<<ans->key<<endl;


    node* ans1 = ceilBst(root,3);
    cout<<ans1->key;
    
    return 0;
}
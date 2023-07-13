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

node* getSucc(node* curr)
{
    //returning right sub tree's left most child
    curr = curr->right;
    while(curr!=NULL and curr->left!=NULL)
    {
        curr = curr->left;
    }

    return curr;
}

node* delBST(node* root,int x)
{
    if(!root)
    {
        return root;
    }

    //search for the root to be deleted

    //node to be deleted is less than root element then search in the left sub tree
    if(root->key > x)
    {
        root->left = delBST(root->left,x);
    }

    //node to be deleted is greater than the root element then search in the right subtree
    else if(root->key < x)
    {
        root->right = delBST(root->right,x);
    }

    //if we found the node then
    else
    {
        if(root->left==NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            node* succ = getSucc(root);
            root->key = succ->key;
            root->right = delBST(root->right,succ->key);
        }
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
    root = delBST(root,16);
    inorder(root);
     
    return 0;
}

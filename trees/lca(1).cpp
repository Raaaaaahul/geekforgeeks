#include<bits/stdc++.h>
using namespace std;
struct Node{
    int key;
    Node* left;
    Node* right;
    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};
bool path(Node* root,vector<int>& p,int n)
{
    if(root==NULL)
    {
        return false;
    }
    p.push_back(root->key);
    if(root->key==n)
    {
        return true;
    }
    if((root->left and path(root->left,p,n)) or (root->right and path(root->right,p,n)))
    {
        return true;
    }
    p.pop_back();
    return false;
}
int lca(Node* root,int n1,int n2)
{
    vector <int >path1,path2;
    if(!path(root,path1,n1) or !(path(root,path2,n2)))
    {
        return -1;
    }
    int i;
    for(i=0;i<path1.size() and i<path2.size();i++)
    {
        if(path1[i]!=path2[i])
        {
            break;
        }
    }
    return path1[i-1];
}
int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->left->left = new Node(50);
    root->right->right = new Node(60);
    root->right->right->right = new Node(70);  
    cout<<"LCA OF THE GIVEN TREE IS : "<<lca(root,20,70);
    return 0;
}
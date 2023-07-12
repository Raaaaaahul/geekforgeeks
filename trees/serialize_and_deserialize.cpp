#include<bits/stdc++.h>
using namespace std;
struct Node{
    int key;
    Node* right;
    Node* left;

    Node(int x)
    {
        key = x;
        right=NULL;
        left = NULL;
    }
};

const int empty = -1;

void serialize(Node* root,vector<int>& v)
{
    if(root==NULL)
    {
        v.push_back(empty);
        return;
    }
    v.push_back(root->key);
    serialize(root->left,v);
    serialize(root->right,v);
}
int idx = 0;
Node* deserialize(vector<int>& v,int idx)
{
    if(idx==v.size())
    {
        return NULL;
    }
    int val = v[idx];
    idx++;
    if(val==empty)
    {
        return NULL;
    }
    Node* root = new Node(val);
    root->left = deserialize(v,idx);
    root->right = deserialize(v,idx);

    return root;
}
void preorder(Node* root)
{
    if(root)
    {
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    vector<int> v;
    serialize(root,v);
    cout<<"serialized vector : "<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
   Node* root_2 = deserialize(v,idx);
   preorder(root_2);


    return 0;
}
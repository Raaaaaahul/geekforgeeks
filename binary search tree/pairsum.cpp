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

void inorder(node* root,vector<int>& v)
{
    if(root)
    {
        inorder(root->left,v);
        v.push_back(root->key);
        inorder(root->right,v);
    }
}

bool method1(vector<int>& v,int k)
{
    int i=0;
    int j = v.size()-1;
    while (i<j)
    {
        if(v[i] + v[j]==k)
        {
            return true;
        }
        else if(v[i] + v[j]<k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return false;
}

bool method2(node* root,unordered_set<int>& s,int k)
{
    if(root==NULL)
        return false;
    
    if(method2(root->left,s,k)==true)
        return true;
    
    if(s.find(k-root->key)!=s.end())
    {
        return true;
    }

    else
        s.insert(root->key);
    
    return method2(root->right,s,k);

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

    vector<int> v;
    unordered_set<int> s;
    inorder(root,v);

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl<<method1(v,21);
    cout<<endl<<method2(root,s,21);
    return 0;
}
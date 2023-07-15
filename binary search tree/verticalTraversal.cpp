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
void vTraversal(node* root)
{
    map<int,vector<int>> mp;
    queue<pair<node*,int>> q;
    q.push({root,0});
    while(q.empty()==false)
    {
        auto p = q.front();
        node* curr = p.first;
        int hd = p.second;
        mp[hd].push_back(curr->key);
        q.pop();
        if(curr->left)
        {
            q.push({curr->left,hd-1});
        }
        if(curr->right)
        {
            q.push({curr->right,hd+1});
        }
    }
    for(auto it:mp)
    {
        vector<int> v = it.second;
        for(auto j : v)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
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
    vTraversal(root);
    return 0;
}

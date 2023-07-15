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
void topview(node* root)
{
    map<int,int> mp;
    queue<pair<node*,int>> q;
    q.push({root,0});
    while(q.empty()==false)
    {
        auto p = q.front();
        int hd = p.second;
        node* curr = p.first;
        if(mp.count(hd)==0)
        {
            mp[hd] = curr->key;
        }
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
    vector<int> v;
    for(auto p:mp)
    {
        v.push_back(p.second);
    }
    for(auto x:v)
    {
        cout<<x<<" ";
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
    topview(root);
    return 0;
}

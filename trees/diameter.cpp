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
void inorder(Node* root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}
int res= 0;
int height(Node* root)
{
    if(root==NULL)
        return 0;
    return max(height(root->left),height(root->right))+1;
}
int diameter(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int d1 = 1+height(root->left) + height(root->right);
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);
    return max(d1,max(d2,d3));

}
int diaEFF(Node* root)
{
    int res = 0;
    if(root==NULL)
    {
        return 0;
    }
    int lh = diaEFF(root->left);
    int rh = diaEFF(root->right);
    res = max(res,lh+rh+1);
    return 1+max(lh,rh);
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

    inorder(root);
    cout<<endl<<"height of tree is : "<<height(root)<<endl;
    cout<<"diameter of the tree is :"<<diameter(root);
    return 0;
}
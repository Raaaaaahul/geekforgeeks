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
int preIdx = 0;
Node* cTree(vector<int>& in,vector<int>& pre,int st,int end)
{
    if(st>end)
    {
        return NULL;
    }
    //creating the first element of the preorder vector as the root
    Node* root = new Node(pre[preIdx++]);

    int inIdx;
    for(int i=st;i<=end;i++)
    {
        if(in[i]==root->key)
        {
            inIdx = i;
            break;
        }
    }
    root->left = cTree(in,pre,st,inIdx-1);
    root->right = cTree(in,pre,inIdx+1,end);
    return root;

}
void inorder(Node* root)
{
    if(!root)return;
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}
int main()
{
    int size;
    cin>>size;
    cout<<endl<<"enter elements for inorder traversal :";
    vector<int> in(size);
    for(int i=0;i<size;i++)
    {
        cin>>in[i];
    }
    cout<<endl<<"enter elements for pre order traversal : ";
    vector<int> pre(size);
    for(int i=0;i<size;i++)
    {
        cin>>pre[i];
    }
    Node* root = cTree(in,pre,0,size-1);
    cout<<endl;
    inorder(root);
    return 0;
}
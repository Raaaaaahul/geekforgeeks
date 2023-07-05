#include<bits/stdc++.h>
using namespace std;
struct Node{
    int key;
    Node* left;
    Node* right;

    Node(int x)
    {
        key = x;
        right=NULL;
        left=NULL;
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
void preorder(Node* root)
{
    if(root)
    {
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node* root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
}
int height(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return (max(height(root->left),height(root->right))+1);
}
void kdist(Node* root,int k)
{
    if(!root)
    {
        return;
    }
    if(k==0)
    {
        cout<<root->key<<" ";
    }
    else
    {
        kdist(root->left,k-1);
        kdist(root->right,k-1);
    }
}

void leveltraversal(Node* root)
{
    int h  = height(root);
    for(int i=0;i<h;i++)
    {
        kdist(root,i);
    }
}
void bfs(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* curr = q.front();
        q.pop();
        cout<<curr->key<<" ";
        if(curr->left!=NULL)
        {
            q.push(curr->left);
        }
        if(curr->right!=NULL)
        {
            q.push(curr->right);
        }
    }
}
void linebyline(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1)
    {
        Node* curr = q.front();
        q.pop();
        if(curr==NULL)
        {
            cout<<endl;
            q.push(NULL);continue;
        }
        cout<<curr->key<<" ";
        if(curr->left!= NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL)
        {
            q.push(curr->right);
        }
    }
}
int getSize(Node* root)
{
    if(!root)
        return 0;
    
    else
        return 1+getSize(root->left) + getSize(root->right);
}
int getMax(Node* root)
{
    if(root==NULL)
    {
        return INT_MIN;
    }
    else
        return max(root->key,max(getMax(root->left),getMax(root->right)));
}
void leftView(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while(q.empty()==false)
    {
        int count = q.size();
        for(int i=0;i<count;i++)
        {
            Node* curr = q.front();
            q.pop();
            if(i==0)
            {
                cout<<curr->key<<" ";
            }
            if(curr->left)
            {
                q.push(curr->left);
            }
            if(curr->right)
            {
                q.push(curr->right);
            }
        }
    }
}
bool cSum(Node* root)
{
    //for empty tree
    if(!root)
    {
        return true;
    }
    //for single node of tree
    if(root->left==NULL and root->right==NULL)
    {
        return true;
    }
    int sum = 0;
    if(root->left!=NULL)
    {
        sum+=root->left->key;
    }
    if(root->right!=NULL)
    {
        sum+=root->right->key;
    }
    return (root->key==sum &&(cSum(root->left)&&cSum(root->right)));
}
int isBal(Node* root)
{
    if(root==NULL)
        return 0;
    
    int lh = isBal(root->left);
    if(lh==-1)
        return -1;
    
    int rh = isBal(root->right);
    if(rh==-1)
        return -1;

    if(abs(lh-rh)>1)
        return -1;
    
    else
        return max(rh,lh)+1;

}
int width1(Node* root)
{
    if(root==NULL)
        return 0;
    
    queue<Node*> q;
    q.push(root);
    int res = 0;
    while(q.empty()==false)
    {
        int count = q.size();
        res = max(res,count);
        for(int i=0;i<count;i++)
        {
            Node* curr = q.front();
            q.pop();
            if(curr->left!=NULL)
            {
                q.push(root->left);
            }
            if(curr->right!=NULL)
            {
                q.push(root->right);
            }
        }
    }
    return res;
}
int main()
{
    Node* root = new Node(10);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(INT_MAX);
    root->left = new Node(20);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    cout<<"height of the tree is "<<height(root); 
    cout<<endl<<"nodes at distance k from the root node"<<endl;
    kdist(root,2);
    cout<<endl;
    leveltraversal(root);
    cout<<endl;
    bfs(root);
    cout<<endl;
    linebyline(root);
    cout<<endl;
    cout<<"size of tree "<<getSize(root);
    cout<<endl<<"max value int tree : "<<getMax(root);
    leftView(root);
    cout<<endl<<"child sum property bool value : "<<cSum(root)<<endl;
    cout<<isBal(root)<<endl;
    if(isBal(root)>-1)
    {
        cout<<"tree is balanced";
    }
    else
    {
        cout<<"tree is not balanced"<<endl;
    }
    cout<<endl<<"width of the tree is : "<<width1(root);
    return 0;
}
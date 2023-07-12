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

void itIn(Node* root)
{
    stack<Node*> st;
    Node* curr = root;
    while(curr!=NULL || st.empty()==false)    
    {
        while(curr!=NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout<<curr->key<<" ";
        curr = curr->right;
    }
}
void itPre(Node* root)
{
    if(root==NULL)
        return;
    
    stack<Node*> st;
    st.push(root);
    while(st.empty()==false)
    {
        Node* curr = st.top();
        cout<<curr->key<<" ";
        st.pop();
        if(curr->right) st.push(curr->right);
        if(curr->left)  st.push(curr->left);
    }
}
int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right = new Node(30);
    itIn(root);cout<<endl;
    itPre(root);cout<<endl;
    return 0;
}
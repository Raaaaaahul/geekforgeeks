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

void spiral(Node* root)
{
    queue<Node*> q;
    q.push(root);
    stack<int> st;
    bool reverse = false;
    while(q.empty()==false)
    {
        int count = q.size();
        for(int i=0;i<count;i++)
        {
            Node* temp = q.front();
            q.pop();
            
            if(reverse)
            {
                st.push(temp->key);
            }
            else
            {
                cout<<temp->key<<" ";
            }
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
        }
        if(reverse)
        {
            while(st.empty()==false)
            {
                cout<<st.top()<<" ";
                st.pop();
            }
        }
        reverse = !reverse;
    }
}
vector<vector<int>> zigzag(Node* root)
{
    vector<vector<int>> res;
    if(!root)
        return;
    
    queue<Node*> q;
    q.push(root);
    int i=0;
    while(!q.empty())
    {
        int size = q.size();
        vector<int> v;
        while(size--)
        {
            auto curr_node = q.front();
            v.push_back(curr_node->key);
            q.pop();
            if(curr_node->left)q.push(curr_node->left);
            if(curr_node->right)q.push(curr_node->right);
        }
        if(i++%2)
        {
            reverse(v.begin(),v.end());
            ans.push_back(v);
        }
    }
    return res;
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
    cout<<endl<<"spiral traversal : "<<endl;
    spiral(root);
    cout<<endl;
    vector<vector<int>> res = zigzag(root);
    return 0;
}

/*5

enter elements for inorder traversal :20 10 40 30 50

enter elements for pre order traversal : 10 20 30 40 50

*/
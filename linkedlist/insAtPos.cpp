#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void traversal(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
Node* insEnd(Node* head,int val)
{
    Node* temp = new Node(val);
    if(head==NULL)
    {
        return temp;
    }
    Node* curr = head;
    while(curr->next!=NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}
Node* insPos(Node* head,int pos, int val)
{
    Node* temp = new Node(val);
    if(pos==1)
    {
        temp->next = head;
        return head;
    }
    Node* curr = head;
    for(int i=0;i<pos-2 && curr!=NULL;i++)
    {
        curr = curr->next;
    }
    if(curr==NULL)
    {
        return head;
    }
    else
    {
        temp->next = curr->next;
        curr->next = temp;
    }
    return head;
}
int main()
{
    Node *head = new Node(1);
    int t = 4;
    while(t--)
    {
        int a;
        cin>>a;
        head=insEnd(head,a);
    }
    cout<<"original list"<<endl;
    traversal(head);cout<<endl;
    insPos(head,5,999);cout<<endl;
    traversal(head);
    return 0;
}
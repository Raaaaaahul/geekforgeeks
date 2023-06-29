#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int x)
    {
        data = x;
        next=NULL;
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
void nthelefromend(Node* head,int n)
{
    int len=0;
    for(Node* curr = head;curr!=NULL;curr=curr->next)
    {
        len++;
    }
    if(len<n)
    {
        return;
    }
    Node* curr = head;
    for(int i=1;i<len-n+1;i++)
    {
        curr = curr->next;
    }
    cout<<curr->data;
}

void printnthNode(Node* head,int n)
{
    if(head==NULL)
        return;
    
    Node* fast = head;
    Node* slow = head;
    for(int i=0;i<n;i++)
    {
        if(fast==NULL) return;
        fast = fast->next;
    }
    while(fast!=NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    cout<<slow->data;
}
int main()
{
    Node* head = new Node(10);
    int n = 5;
    while(n--)
    {
        int a;
        cin>>a;
        head = insEnd(head,a);
    }
    traversal(head);
    nthelefromend(head,2);
    cout<<endl;
    printnthNode(head,4);
    return 0;
}

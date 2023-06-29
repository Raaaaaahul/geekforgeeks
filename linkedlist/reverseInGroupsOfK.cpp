#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
    node()
    {
        next=NULL;
    }
    node(int x)
    {
        data = x;
        next=NULL;
    }
};
node* insEnd(node* head,int val)
{
    node* temp = new node(val);
    if(head==NULL)
    {
        return temp;
    }
    node* curr = head;
    while(curr->next!= NULL)
    {
        curr = curr->next;
    }
    curr->next=temp;
    return head;
}
void traverse(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
node *reverseKgroups(node* head,int k)
{
    //first k elements are reversed
    node* curr=head;
    node* prev=NULL;
    node* next=NULL;
    int count = 0;
    while(curr!=NULL and count<k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next!=NULL)
    {
        node* head_rest = reverseKgroups(next,k);
        head->next = head_rest;
    }
    return prev;
}
int main()
{
    node* head = new node(1);
    int n =7;
    while(n--)
    {
        int a;
        cin>>a;
        head = insEnd(head,a);
    }
    traverse(head);
    int k = 3;
    head = reverseKgroups(head,k);
    traverse(head);
    return 0;
}
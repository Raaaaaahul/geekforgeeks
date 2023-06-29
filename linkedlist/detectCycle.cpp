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
node* lastNode(node* head)
{
    while(head!=NULL)
    {
        head = head->next;
    }
    return head;
}
bool detectCycle(node* head)
{
    unordered_set<node*> s;
    for(node* curr=head;curr!=NULL;curr = curr->next)
    {
        if(s.find(curr)!=s.end())
        {
            return true;
        }
        s.insert(curr);
    }
    return false;
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
    node* last = lastNode(head);
    last->next = head;
    cout<<detectCycle(head);
    return 0;
}
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
node* segregate(node* head)
{
    node* eStart = NULL;
    node* eEnd = NULL;
    node* oStart = NULL;
    node* oEnd = NULL;
    for(auto curr = head;curr!=NULL;curr = curr->next)
    {
        int val = curr->data;
        if(val%2==0)
        {
            if(eStart==NULL)
            {
                eStart = curr;
                eEnd = eStart;
            }
            else
            {
                eEnd->next = curr;
                eEnd = eEnd->next;
            }
        }
        else
        {
            if(oStart==NULL)
            {
                oStart = curr;
                oEnd = oStart;
            }
            else
            {
                oEnd->next = curr;
                oEnd = oEnd->next;
            }
        }
    }
    if(eStart==NULL or oStart==NULL)
    {
        return head;
    }
    eEnd->next = oStart;
    oEnd->next = NULL;
    return eStart;
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
    head = segregate(head);
    traverse(head);
    return 0;
}
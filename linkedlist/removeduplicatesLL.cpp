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
node* removedups(node* head)
{
    if(head==NULL or head->next==NULL)
    {
        return head;
    }
    else{
        node* curr = head;
        while(curr!=NULL and curr->next!=NULL)
        {
            if(curr->data==curr->next->data)
            {
                node* temp = curr->next;
                curr->next = curr->next->next;
                delete (temp);
            }
            else{
                curr = curr->next;
            }
        }
    }
    return head;
}
int main()
{
    node* head = new node(1);
    int n = 5;
    while(n--)
    {
        int a;
        cin>>a;
        head = insEnd(head,a);
    }
    traverse(head);
    head = removedups(head);
    traverse(head);
    return 0;
}
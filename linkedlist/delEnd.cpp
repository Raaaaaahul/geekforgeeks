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
Node* begInsert(Node* head,int val)
{
    Node* temp = new Node(val);
    temp->next = head;
    return temp;
}

void traversal(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
Node* delEnd(Node* head)
{
    if(head==NULL)  return NULL;
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    Node* curr = head;
    while(curr->next->next!=NULL)
    {
        curr = curr->next;
    }
    delete(curr->next);
    curr->next = NULL;
    return head;
}
int main()
{
    Node* head = NULL;
    head = begInsert(head,10);
    head = begInsert(head,20);
    head = begInsert(head,30);
    traversal(head);
    cout<<endl;
    head = delEnd(head);
    traversal(head);
   return 0;
}
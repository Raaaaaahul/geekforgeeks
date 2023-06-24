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
        cout<<head->data<<"->";
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
Node* delBeg(Node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node* temp = head->next;
    delete (head);
    return temp;
}
int main()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    traversal(head);
    cout<<"inserting new element 40"<<endl;
    head = insEnd(head,40);
    traversal(head);
    cout<<endl<<endl;
    Node* head1 = NULL;
    head1 = insEnd(head1,100);
    traversal(head1);
    head = delBeg(head);
    traversal(head);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* next;
    
    Node()
    {
        next = NULL;
    }
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void traverse(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* sortedIns(Node* head,int x)
{
    Node* temp = new Node(x);
    if(head==NULL)
    {
        return temp;
    }
    if(x<head->data)
    {
        temp->next = head;
        return temp;
    }

    Node* curr = head;
    while(curr->next!=NULL and curr->next->data < x)
    {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;

    return head;
}

int main()
{
    Node* head = new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next = new Node(40);
    traverse(head);
    head = sortedIns(head,23);
    traverse(head);
    return 0;
}
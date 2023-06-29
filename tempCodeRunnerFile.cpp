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
Node* reverse(Node *head){
    Node* curr = head;
    Node* prev = NULL;
    while(curr!=NULL)
    {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
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
    head = reverse(head);
    traversal(head);
    return 0;
}
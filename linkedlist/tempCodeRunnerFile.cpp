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
void printmiddle(Node* head)
{
    if(head==NULL)
    {
        return;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL and fast->next->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<<slow->data;
}
int main()
{
    Node* head = new Node(10);
    int n = 4;
    while(n--)
    {
        int a;
        cin>>a;
        head = insEnd(head,a);
    }
    traversal(head);
    printmiddle(head);    
    // head = oddEvenList(head);
    // traversal(head);
    return 0;
}

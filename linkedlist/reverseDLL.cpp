#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int x)
    {
        data = x;
        prev=NULL;
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
Node* reverse(Node* head)
{
    if(head==NULL or head->next==NULL)
        return head;
    Node* temp = NULL;
    Node* curr = head;
    while(curr!=NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    return temp->prev;
}
int main()
{
    Node* head = new Node(10);
    Node* temp1 = new Node(20);
    Node* temp2 = new Node(30);
    Node* temp3 = new Node(40);

    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev =temp1;
    temp2->next = temp3;
    temp3->prev = temp2;

    traversal(head);
    head = reverse(head);
    traversal(head);
    return 0;
}
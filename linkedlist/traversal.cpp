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
void recursiveTraversal(Node* head)
{
    if(head==NULL)
        return;
    cout<<(head->data)<<" ";
    recursiveTraversal(head->next);
}

int main()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    traversal(head);
    recursiveTraversal(head);
    return 0;
}
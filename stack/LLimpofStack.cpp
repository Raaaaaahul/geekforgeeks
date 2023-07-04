#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};
struct myStack{
    
    node* head;
    int sz;
    
    myStack()
    {
        head = NULL;
        sz = 0;
    }

    void push(int val)
    {
        node* temp = new node(val);
        temp->next = head;
        head = temp;
        sz++;
    }

    int pop()
    {
        if(head==NULL)
        {
            cout<<"stack under flow"<<endl;
            return INT_MAX;
        }
        int res = head->data;
        node* temp = head;
        head = head->next;
        delete temp;
        sz--;
        return res;
    }

    int size()
    {
        return sz;
    }

    bool isEmpty()
    {
        if(head==NULL)
        {
            return true;
        }
        return false;
    }

    int peek()
    {
        if(head==NULL)
        {
            cout<<"stack underflow"<<endl;
            return INT_MAX;
        }
        return head->data;
    }

};


int main()
{
    myStack s;
    s.push(12);
    s.push(32);
    s.push(14);
    cout<<s.peek()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isEmpty();
    return 0;
}
Node *removeLoop(Node *head)
{
    Node* slow = head;
    Node* fast = head;
    Node* curr= head;
    bool flag = false;
    while(fast != NULL && fast->next != NULL )
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast==slow)
        {
            break;
        }
        
    }
    if(slow != fast)
        {return head;}
    slow = head;
    while(slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;

    }
    fast->next = NULL;
    return head;
}
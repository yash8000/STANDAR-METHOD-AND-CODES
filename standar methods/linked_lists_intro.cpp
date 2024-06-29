#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value){
        data=value;next=nullptr;
    }

};

void insertbegin(Node* &node,int value)
{
    Node* newnode=new Node(value);
    newnode->next=node;
    newnode->data=value;
    node=newnode;
}

void insertend(Node* &head,int value)
{
    Node* cur=head;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    Node* newnode=new Node(value);
    cur->next=newnode;
    
}



int main()
{
    Node* head=new Node(10);
    // head->data=5ṇ;
    // head->next=NULL;
    insertbegin(head, 20);
    insertbegin(head, 30);
    insertbegin(head, 50);
    insertend(head, 5);
    insertend(head, 1);

    cout<<head<<endl;
    
    cout<<head->data<<endl;
    cout<<head->next->data<<endl;
    cout<<head->next->next->data<<endl;
    cout<<head->next->next->next->data<<endl;
    cout<<head->next->next->next->next->data<<endl;
    cout<<head->next->next->next->next->next->data<<endl;

    cout<<head->next<<endl;
    cout<<head->next->next<<endl;
    cout<<head->next->next->next<<endl;
    cout<<head->next->next->next->next<<endl;
    cout<<head->next->next->next->next->next<<endl;
    cout<<head->next->next->next->next->next->next<<endl;
    return 0;
}
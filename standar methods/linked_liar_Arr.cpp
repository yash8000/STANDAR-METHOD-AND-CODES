#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node()
    {
        data=0;
        next=nullptr;
    }
    Node(int val)
    {
        data=val;
        next=nullptr;
    }
    Node(Node *h,int val)
    {
        data=val;
        next=h;
    }
};
Node* convert_array_to_LL(vector<int>&v)
{
      Node *head=new Node(v[0]);// points to fist elemnt of the array
      Node *mover=head;         // KEEPS pointinf to end of LL to make sure new node are attached to it
      
      for(int i=1;i<v.size();i++)
      {
          Node *temp=new Node(v[i]);
          mover -> next = temp;
          mover = temp;      //mover= mover -> next

      }
      return head;
}

int length_of_LL(Node* head)
{
    Node * temp=head;
    int c=0;
    while(temp)
    {
        c++;
        temp=temp->next;
    }
    return c;
}

int check_if_present(Node *head,int val)
{
    Node *temp=head;
    int c=0;
    while(temp)
    {

        if(temp->data==val)
           return c;
        c++;
        temp=temp->next;   
    }
    return -1;

}
int main()
{
    vector<int>v={1,2,3,40,5};

    // Node *head=new Node(v[0]);
    // cout<<head<<endl;
    // cout<<head->data<<endl;
    // cout<<head->next<<endl;

    Node* head=convert_array_to_LL(v);
    cout<<head->data<<endl;

    Node *cur=head;
    

    while(cur!=NULL)
    {
        // auto p=cur->next;
        // auto p=cur->next;
        if(cur->next!=NULL)
        cout<<cur->data<<" -> ";
        else
        cout<<cur->data<<" -> NULL";
        
        cur=cur->next;
    }
    cout<<endl;

    cout<<"THE LENGTH OF THE LINKED LIST IS : "<<length_of_LL(head)<<endl;
    

    cout<<"THE VALUE 5 IS AT : "<<check_if_present(head,5)<<endl;
    
}
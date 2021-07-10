#include <bits/stdc++.h>
using namespace std;

struct Node { 
public:
    int data; 
    struct Node *next;
    Node(int x){
       this->data=x;
       this->next=NULL;
   }
}; 

struct Node* head = NULL;   

void display() { 
   struct Node* ptr;
   ptr = head;
   cout<<"The linked list is: ";
   while (ptr != NULL) { 
      cout<< ptr->data <<" "; 
      ptr = ptr->next; 
   }
   cout<<endl;
}

void insertBeg(int new_data) { 
   struct Node* new_node = new Node(new_data); 
   new_node->next = head; 
   head = new_node;
   cout<<"An Element is Inserted At Beginning"<<endl; 
   display();
}

void removeBeg() {  
    if(head == NULL){
        cout<<"List is empty, Cannot Delete an Element"<<endl;
        return;
    }
    
    struct Node* ptr; 
    ptr = head;  
    head = ptr->next;  
    delete ptr; 
    cout<<"An Element is Deleted At Beginning"<<endl; 
    
    display();
}

void insertEnd(int new_data){
    struct Node* new_node = new Node(new_data);
    if(head==NULL){
        new_node->next=head;
        head=new_node;
        cout<<"An Element is Inserted At End"<<endl;
        return;
    }
    struct Node* ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=new_node;
    cout<<"An Element is Inserted At End"<<endl;
    display();
}


void removeEnd(){
    if(head == NULL){
        cout<<"List is empty, Cannot Delete an Element"<<endl;
        return;
    }

    struct Node *ptr,*ptr1;
    if(head->next==NULL){
        head=NULL;
        delete head;
    }
    else{
        ptr=head;
        while(ptr->next!=NULL){
            ptr1=ptr;
            ptr=ptr->next;
        }
        ptr1->next=NULL;
        delete ptr;
    }
    cout<<"An Element is Deleted At End"<<endl; 
    display();
}

void insertPos(int new_data,int pos){
    if(pos<0){
        cout<<"Cannot insert at this position"<<endl;
        return;
    }
    Node *temp=head;
    struct Node *new_node= new Node(new_data);
    if(pos==0) {
        new_node->next = head; 
        head = new_node;
        cout<<"Successfully Inserted"<<endl;
        display();
        return;
    }
    if(pos>0){
        if(head==NULL){
            cout<<"Cannot be inserted"<<endl;
            return;
        }
    }
    while(--pos){
        temp=temp->next;
        if(temp==NULL){
            cout<<"Cannot be inserted at this position"<<endl;
            return;
        }
    }
    new_node->next=temp->next;
    temp->next=new_node;
    cout<<"Successfully Inserted"<<endl;
    display();
}

void removePos(int pos){
    if(head == NULL){
        cout<<"List is empty, Cannot Delete an Element"<<endl;
        return;
    }
    if(pos<0){
        cout<<"Cannot Delete at this position"<<endl;
        return;
    }
    Node *temp=head;
    if(pos==0){
        temp=temp->next;
        head=temp;
        cout<<"Successfully Deleted"<<endl;
        display();
        return;
    } 
    while(--pos){
        temp=temp->next;
        if(temp==NULL){
            cout<<"Cannot be Delete at this position"<<endl;
            return;
        }
    }
    if(temp->next==NULL){
        cout<<"Cannot be Delete at this position"<<endl;
        return;
    }
    temp->next=temp->next->next;
    cout<<"Successfully Deleted"<<endl;
    display();
}

/*id reverse(){
    Node *revhead=NULL;
    Node *head1=head;
    while(head1){
        Node *temp=head1->next;
        head1->next=revhead;
        revhead=head1;
        head1=temp;
    }
    Node *ptr;
    ptr= revhead;
    cout<<"The Reverse Linked List is:";
   while (ptr != NULL) { 
      cout<< ptr->data <<" "; 
      ptr = ptr->next; 
   }
   cout<<endl;
}

reverse();
*/

int main(){
   insertEnd(0);
   insertEnd(1);
   insertEnd(2);
   insertEnd(3);
   insertEnd(4);
   insertEnd(5);
  
   
   display();
    
   return 0; 
}

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data = data;
        this->next=NULL;
    }
};

void PrintLL(Node* &head){
    Node* temp=head;
    cout<< "Linked List: ";
    while(temp!=NULL){
        cout << temp -> data << "->";
        temp = temp-> next;
    }
    cout<< "NULL" << endl;
}

void InsertAtBegin(Node* &head,int data){
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
}



void InsertAtEnd(Node* &head,int data){
    Node* NewNode = new Node(data);
    Node* temp=head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next=NewNode;
}

void InsertAtPos(Node* &head,int pos,int data){
    if(pos <=1){
        InsertAtBegin(head,data);
    }
    int count=1;
    Node* temp = head;
    while(count<pos-1){
        temp=temp->next;
        count++;
    }
    if(temp == NULL){
        InsertAtEnd(head,data);
        return;
    }
    Node* NewNode = new Node(data);
    NewNode->next=temp->next;
    temp->next=NewNode;
}

void DeleteAtBegin(Node* &head){
    if(head == NULL){
        cout << "List is Empty.. " << endl;
        return;
    }
    Node* temp=head;
    head=head->next;
    cout<< "Deleted: "<< temp->data <<endl;
    free(temp);
}

void DeleteAtEnd(Node* &head){
    if(head == NULL){
        cout << "List is Empty.. " << endl;
        return;
    }
    Node* temp=head;
    while(temp->next->next!= NULL){
        temp = temp->next;
    }
    Node* temp2= temp->next;
    temp->next=NULL;
    cout<< "Deleted: "<< temp2->data <<endl;
    free(temp2); 
}

int main(){
    Node* head = new Node(10);
    PrintLL(head);
    InsertAtBegin(head,20);
    PrintLL(head);
    InsertAtBegin(head,30);
    PrintLL(head);
    InsertAtEnd(head,40);
    PrintLL(head);
    InsertAtPos(head,3,50);
    PrintLL(head);

    DeleteAtBegin(head);
    PrintLL(head);
    DeleteAtEnd(head);
    PrintLL(head);
}
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};

void PrintDLL(Node* &head){
    if(head == NULL){
        cout << "List is Empty.." << endl;
        return;
    }
    cout << "Doubly Linked List: ";
    Node* temp = head;
    cout << "NULL <-> ";
    while( temp!= NULL){
        cout << temp->data << " <-> ";
        temp=temp->next;
    }
    cout << "NULL" << endl;
}

void InsertAtBegin(Node* &head,Node* &tail,int data){
    if(head == NULL){
        head = new Node(data);
        tail=head;
    }else{
        Node* NewNode = new Node(data);
        NewNode->next=head;
        head->prev=NewNode;
        head=NewNode;
    }
}

void InsertAtEnd(Node* &head, Node* &tail, int data){
    if(head == NULL){
        head = new Node(data);
        tail = head;
    }else{
        Node* NewNode = new Node(data);
        NewNode->prev=tail;
        tail->next=NewNode;
        tail=NewNode;
    }
}

void InsertAtPos(Node* &head,Node* &tail,int data,int pos){
    if(pos <=1){
        InsertAtBegin(head,tail,data);
        return;
    }

    Node* temp = head;
    int count=1;
    while (count < pos-1)
    {
       temp=temp->next;
       count++;
    }

    if(temp == NULL || temp->next == NULL){
        InsertAtEnd(head,tail,data);
        return;
    }

    Node* NewNode = new Node(data);
    NewNode->next=temp->next;
    temp->next->prev=NewNode;
    temp->next=NewNode;
}

void DeleteAtBegin(Node* &head,Node* &tail){
    if(head == NULL){
        cout << "List is Empty.." << endl;
        return;
    }
    if(head == tail){
        Node* temp = head;
        head=NULL;
        tail=NULL;
        cout << "Deleted last element: " << temp->data << endl;
        free(temp);
        return;
    }
    Node* temp = head;
    cout << "Deleted: " << temp->data << endl;
    head=head->next;
    head->prev=NULL;
    free(temp);
}

void DeleteAtEnd(Node* &head,Node* &tail){
    if(tail == NULL){
        cout << "List is Empty.." << endl;
        return;
    }
    if(head == tail){
        Node* temp = head;
        head=NULL;
        tail=NULL;
        cout << "Deleted last element: " << temp->data << endl;
        free(temp);
        return;
    }
    Node* temp = tail;
    cout << "Deleted: " << temp->data << endl;
    tail=tail->prev;
    tail->next=NULL;
    free(temp);
}

void DeleteAtPos(Node* &head,Node* &tail,int pos){
    if(pos<=1){
        DeleteAtBegin(head,tail);
        return;
    }
    Node* temp = head;
    int count=1;
    while (count < pos-1)
    {
       temp=temp->next;
       count++;
    }

    if(temp==NULL || temp->next->next == NULL){
        DeleteAtEnd(head,tail);
        return;
    }

    Node* temp2=temp->next;
    cout << "Deleted: " << temp2->data << endl;
    temp->next=temp2->next;
    temp->next->prev=temp;
    free(temp2);

}

int main(){

    Node* head = new Node(10);
    Node* tail = head;
    PrintDLL(head);


    InsertAtEnd(head,tail,40);
    PrintDLL(head);

    InsertAtPos(head,tail,50,3);
    PrintDLL(head);

    cout<<head->data<< endl;
    cout<<tail->data << endl;

    DeleteAtBegin(head,tail);
    PrintDLL(head);
    DeleteAtEnd(head,tail);
    PrintDLL(head);

    DeleteAtBegin(head,tail);
    PrintDLL(head);

    InsertAtBegin(head,tail,20);
    PrintDLL(head);
    InsertAtBegin(head,tail,30);
    PrintDLL(head);
    InsertAtEnd(head,tail,40);
    PrintDLL(head);

    DeleteAtPos(head,tail,2);
    PrintDLL(head);

}
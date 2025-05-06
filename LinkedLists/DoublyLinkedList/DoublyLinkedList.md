# Doubly LinkedList

## Node Creation
```cpp
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
```
## DLL Initialisation
```cpp
  Node* head= new Node(10);
```

## Printing DLL
```cpp
void PrintDLL(Node* &head){
    if(head == NULL){
        cout << "List is Empty.." << endl;
        return;
    }
    cout << "Doubly Linked List: ";
    Node* temp = head;
    while( temp!= NULL){
        cout<< temp->data << " -> ";
        temp=temp->next;
    }
    cout<< "NULL" << endl;
}
```
## Insert At Begin
```cpp
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
```

## Insert At End
```cpp
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
```

## Insert At Position

```cpp
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

    if(temp == NULL){
        InsertAtEnd(head,tail,data);
        return;
    }

    Node* NewNode = new Node(data);
    NewNode->next=temp->next;
    temp->next->prev=NewNode;
    temp->next=NewNode;
}
```